//
//  ios.h
//  ios
//
//  Created by 张鹏 on 15/7/30.
//  Copyright (c) 2015年 Vbyte Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, VPEventCode) {
    INITED = 10000000,           // 公共的，对上层说已经初始化完毕
    EXIT,                        // 公告的，由上层告知要退出这个系统
    EXITING,                     // 公共的，对上层说正在退出
    EXITED,                      // 公共的，对上层说已经完全退出
    STREAM_READY,                // 公共的，流已经准备就绪
    CONF_READY,                  // 公共的，配置已经就绪
    STUN_CONNECTED,              // 公共的，点播，直播都在监听一个，且同一时刻，只能有一个监听此信号
    JOINED,                      // 公共的，属于tracker的
    PARTNER_READY,               // 公共的，伙伴已经就绪
    NEW_PARTNER,                 // 公共的，有一个新的伙伴
    P2P_STABLE,                  // 公共的，表明P2P稳定
    REPORTED,                    // 公共的，监听的上报信号
    DATA_UNBLOCK                 //
};

typedef NS_ENUM(NSInteger, VPErrorCode) {
    CONF_UNAVAILABLE = 10001000,    // 公共的，配置服务的
    AUTH_FAILED,                    // 公共的，配置服务的
    CONF_INVALID,                   // 公共的，配置服务的
    SRC_UNSTABLE,                   // 资源网络不好
    MEDIA_ERROR,                    // 多媒体格式不对
    BAD_NETWORK,                    // 公共的 网络不好
    STUN_FAILED,                    // 公共的
    JOIN_FAILED,                    // 公共的，属于tracker的
    REPORT_FAILED,                  // 公共的，上报服务的
    UNKNOWN_PACKET,                 // 公共的，收发包逻辑
    INVALID_PACKET,                 // 公共的，收发包
    DATA_BLOCK
};


typedef NS_ENUM(NSInteger, VPVodEventCode) {
    VOD_START = 10020000,       // 仅仅属于点播的，启动一个频道
    VOD_STARTED,
    VOD_STOP,                   // 仅仅属于直播的，停止一个频道
    VOD_STOPPED,
    VOD_PAUSE,                  // 点播专有，暂停
    VOD_RESUME,                 // 点播专有，恢复
    VOD_RETRIEVE_URL,           // 通知应用层要重新获取防盗链url
    VOD_RETRIEVED_URL,          // 应用层已经重新生成了url
    VOD_FINISHED                // 表明CDN探针已经探测到最后一帧
};
    
typedef NS_ENUM(NSInteger, VPVodErrorCode) {
    VOD_URI_EMPTY = 10021000,          // URI为空
    VOD_DOWNLOAD_FAILED,               // SOURCE下载失败
    VOD_FORMAT_INVALID                 // 文件格式不支持
};

extern NSMutableArray *loadQueue;
extern dispatch_queue_t vbyteP2PQueue;

// 事件代理,上层应用需集成来监听事件状态和错误信息
@protocol VPEventDelegate <NSObject>

@required
// 事件信息接口
- (void) onEvent: (int)code msg:(NSString *)msg;
// 错误信息接口
- (void) onError: (int)code msg:(NSString *)msg;

@end

//----------------- p2pModule ---------------------------------------
@interface VPModule : NSObject
// P2PModul 依赖libstd++.tdb, videotool.framework
// 初始化P2P模块，在didFinishLaunchingWithOptions中调用
+ (int) init:(NSString *)appId appKey:(NSString *)appKey appSecretKey:(NSString *)appSecretKey;
// P2P模块释放函数，在applicationWillTerminate中调用
+ (void) release;
// 设置事件代理
+ (void) setDelegate: (id<VPEventDelegate>) delegate;
+ (id<VPEventDelegate>) getDelegate;
// 打印版本信息
+ (NSString *) version;
// debug 开关
+ (void) enableDebug;
+ (void) disableDebug;
@end



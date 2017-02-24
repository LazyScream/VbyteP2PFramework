//
//  VPLiveController+VPLiveController.h
//  advancep2p.ios
//
//  Created by 张鹏 on 2017/2/17.
//  Copyright © 2017年 Vbyte Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, VPLiveEventCode) {
    LIVE_START = 10010000,       // 仅仅属于直播的，启动一个频道
    LIVE_STARTED,
    LIVE_STOP,                   // 仅仅属于直播的，停止一个频道
    LIVE_STOPPED,
    LIVE_LOAD_READY
};

typedef NS_ENUM(NSInteger, VPLiveErrorCode) {
    LIVE_CHANNEL_EMPTY = 10011000,           // 仅仅是直播的
    LIVE_NO_SUCH_CHANNEL,                    // 仅仅直播的
    LIVE_RESOLUTION_INVALID,                 // 仅仅直播的，点播应有自己的一套
    LIVE_FORMAT_INVALID                      // 仅仅直播的，setMediaFormat与conf的不一致
};

@interface VPLiveController : NSObject
/*
 *  加载p2p直播频道，通过输入channel等参数，返回可供播放器播放的p2p uri.
 *  若加载失败，P2PStreamDelegate 会返回相应错误码.
 *  param[in] channel      直播频道ID
 *  param[in] resoltion    分辨率
 *  param[in] startTime    播放起始时间（unix标准时间，针对时移功能）
 *  ret   可供播放器播放的p2p uri.
 */
+ (void) load: (NSString *)channel resolution:(NSString *)resoltion listener:(void(^)(NSURL*))listener;
+ (void) load: (NSString *)channel resolution:(NSString *)resoltion startTime:(double)startTime listener:(void(^)(NSURL*))listener;
// 退出播放
+ (void) unload;

+ (void) onEvent: (int)code msg:(NSString *)msg;
+ (void) onError: (int)code msg:(NSString *)msg;

@end

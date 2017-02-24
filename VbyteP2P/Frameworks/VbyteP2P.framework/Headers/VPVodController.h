//
//  VPLoadEvent+VPVodController.h
//  advancep2p.ios
//
//  Created by 张鹏 on 2017/2/17.
//  Copyright © 2017年 Vbyte Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VPSecurityUrl.h"

// 防盗链Url生成器
@protocol VPUrlGenerator <NSObject>

@required

- (VPSecurityUrl *) createSecurityUrl: (NSString *)sourceId;

@end

extern id<VPUrlGenerator> urlGenerator;

//----------------- p2p 点播接口 -------------------------------------------
@interface VPVodController : NSObject
/*
 *  加载p2p点播频道，通过输入uri等参数，返回可供播放器播放的p2p uri.
 *  若加载失败，P2PStreamDelegate 会返回相应错误码.
 *  param[in] uri          视频原始uri
 *  param[in] resoltion    分辨率
 *  param[in] startTime    播放偏移时间（s）
 *  ret   可供播放器播放的p2p uri.
 */
+ (void) load: (NSString *)channel resolution:(NSString *)resoltion startTime:(double)startTime listener:(void(^)(NSURL*))listener;

+ (void) load: (NSString* )channel resolution:(NSString* )resoltion listener:(void(^)(NSURL*))listener;

// 退出播放，当切换频道或关闭时调用该接口
+ (void) unload;
// 暂停播放
+ (void) pause;
// 恢复播放
+ (void) resume;

+ (void) setUrlGenerator: (id<VPUrlGenerator>) urlGenerator;
+ (id<VPUrlGenerator>) getUrlGenerator;

+ (void) onEvent: (int)code msg:(NSString *)msg;
+ (void) onError: (int)code msg:(NSString *)msg;

@end


//
//  VPLoadEvent+VPLoadEvent.h
//  advancep2p.ios
//
//  Created by 张鹏 on 2017/2/17.
//  Copyright © 2017年 Vbyte Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, VPVideoType) {
    VIDEO_LIVE, VIDEO_VOD
};

@interface VPLoadEvent: NSObject

@property (copy) NSString *channel;
@property (copy) NSString *resolution;
@property double startTime;
@property VPVideoType videoType;
@property (copy) void (^onLoaded)(NSURL* url);

- (id)initWith:(NSString*)chan resolution:(NSString*)relt startTime:(double)st videoType:(VPVideoType)vt listener:(void(^)(NSURL*))ol;

@end

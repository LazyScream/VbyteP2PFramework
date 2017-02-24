//
//  VbyteVodCtrl+VPSecurityURL.h
//  advancep2p.ios
//
//  Created by 张鹏 on 2017/1/13.
//  Copyright © 2017年 Vbyte Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import <Foundation/NSDictionary.h>

@interface VPSecurityUrl : NSObject

@property (copy) NSString *url;
@property (copy) NSString *method;
@property (copy) NSMutableDictionary *headers;

- (VPSecurityUrl *) init;
- (VPSecurityUrl *) initWithUrl:(NSString *)url;
- (VPSecurityUrl *) initWithUrlAndMethod:(NSString *)url method:(NSString *) method;

- (VPSecurityUrl *) addHeader: (NSString *)header value:(NSString *)value;

- (NSString *) jsonSerialize;

@end

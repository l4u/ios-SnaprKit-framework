//
//  SNSnaprEffect.h
//  SnaprKit
//
//  Created by Ryan Maxwell on 23/01/12.
//  Copyright (c) 2012 Cactuslab. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SNSnaprEffect : NSObject

@property (strong, nonatomic) NSDictionary *configuration;
@property (nonatomic, readonly) NSString *displayName;
@property (nonatomic, readonly) BOOL isLocked;
@property (nonatomic, readonly) BOOL isHidden;
@property (nonatomic, readonly) NSString *lockedMessage;

- (UIImage *)applyEffectToImage:(UIImage *)image;

@end

//
//  SnaprKitConfig.h
//  SnaprKit
//
//  Copyright (c) 2012 Snapr. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const SNInvalidConfigurationException;

@protocol SnaprKitDelegate;

/**
 * SnaprKit Configuration Singleton
 */
@interface SnaprKitConfig : NSObject

@property (nonatomic, weak) id<SnaprKitDelegate> delegate;

/** 
 Singleton instance, which will remain alive for the lifetime of your application.
 */
+ (instancetype)sharedInstance;

/**
 Explicitly set the Snapr credentials that will be used, if you have acquired them from the user or elsewhere (stored in User Defaults).
 
 @param username        Snapr username
 @param accessToken     Snapr API Access Token
 */
- (void)setUsername:(NSString *)username accessToken:(NSString *)accessToken;

/**
 Removes any user settings from User Defaults
 */
- (void)clearUsernameAndAccessToken;

@end


/**
 * Delegate objects of SnaprKit assigned to the id<SnaprKitDelegate> delegate property
 */
@protocol SnaprKitDelegate <NSObject>
@optional

/**
 The delegate will be notified when any URLs in the HTML that begin with the `snaprkit-parent://` scheme are tapped
 
 @param url The called URL
 */
- (void)snaprKitParentURLWasCalled:(NSURL *)url;
@end


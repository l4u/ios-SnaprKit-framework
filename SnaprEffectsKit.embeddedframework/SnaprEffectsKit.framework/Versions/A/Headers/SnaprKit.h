//
//  SnaprKit.h
//  SnaprKit
//
//  Copyright (c) 2012 Snapr. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SNViewController.h"

extern NSString * const SNInvalidConfigurationException;

@protocol SnaprKitDelegate;

/**
 * SnaprKit Configuration Singleton
 */
@interface SnaprKit : NSObject

@property (nonatomic, weak) id<SnaprKitDelegate> delegate;

/**
 Show the effect view after picking an image.
 
 @return Defaults to NO
 
 @warning This option is mutually exclusive with `showStickerEffectsView`
 @exception SNInvalidConfigurationException Thrown if set in conjunction with `showStickerEffectsView`
 */
@property (nonatomic, assign) BOOL showEffectsView;

/**
 Show the sticker effect view after picking an image.
 
 @return Defaults to NO
 
 @warning This option is mutually exclusive with `showEffectsView`
 @exception SNInvalidConfigurationException Thrown if set in conjunction with `showEffectsView`
 */
@property (nonatomic, assign) BOOL showStickerEffectsView;

/**
 Array of SNFilterPack Objects
 */
@property (strong, nonatomic, readonly) NSMutableArray *filterPacks;

/**
 Array of SNStickerPack Objects
 */
@property (strong, nonatomic, readonly) NSMutableArray *stickerPacks;

/**
 Assign an Array of Effect Constants. Typically these are defined as extern NSString* in a header file.
 */
@property (nonatomic, strong) NSArray *effectConstants;

/**
 Configuration for the effects.
 
 Each key begins with an Effect Constant (matching the effectConstants property), followed by a "." then the subkey name.
 
 @{@"PinkSummerEffect.locked" : @"You need 1,000 PINK points to unlock this filter."}
 
 */
@property (nonatomic, strong) NSDictionary *effectsConfiguration;

/**
 Crop images to a square?
 
 @return Defaults to NO
 */
@property (nonatomic, assign) BOOL cropToSquare;

/** 
 Assign your configuration options once to this singleton instance, which will remain alive for the lifetime of your application.
 */
+ (instancetype)sharedKit;

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


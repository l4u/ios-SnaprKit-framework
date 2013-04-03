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
 
 @deprecated            Use `setUsername:displayUsername:accessToken` instead
 */
- (void)setUsername:(NSString *)username accessToken:(NSString *)accessToken DEPRECATED_ATTRIBUTE;

/**
 Explicitly set the Snapr credentials that will be used, if you have acquired them from the user or elsewhere (stored in User Defaults).
 
 @param username        Snapr username
 @param displayUsername Snapr display username
 @param accessToken     Snapr API Access Token
 */
- (void)setUsername:(NSString *)username displayUsername:(NSString *)displayUsername accessToken:(NSString *)accessToken;

/**
 Removes any user settings from User Defaults
 
 @deprecated        Use `removeUserSettings` instead
 */
- (void)clearUsernameAndAccessToken DEPRECATED_ATTRIBUTE;

- (void)removeUserSettings;

#if SNAPRKIT_FX

/**
 For setting a single filter's settings
 
 @param settings        a dictionary with `@{@"key": @"value"}` structure
 @param filterSlug      the filter slug
 @param packSlug        the filter pack slug
 */
- (void)setSettings:(NSDictionary *)settings forFilter:(NSString *)filterSlug inPack:(NSString *)packSlug;

/**
 Retrieve the current settings of a filter
 
 @param filterSlug      the filter slug
 @param packSlug        the filter pack slug
 
 @return a dictionary of the current settings
 */
- (NSDictionary *)settingsForFilter:(NSString *)filterSlug inPack:(NSString *)packSlug;

/**
 For setting a single sticker's settings
 
 @param settings        a dictionary with `@{@"key": @"value"}` structure
 @param stickerSlug     the sticker slug
 @param packSlug        the sticker pack slug
 */
- (void)setSettings:(NSDictionary *)settings forSticker:(NSString *)stickerSlug inPack:(NSString *)packSlug;


/**
 Retrieve the current settings of a sticker
 
 @param stickerSlug     the sticker slug
 @param packSlug        the sticker pack slug
 
 @return a dictionary of the current settings
 */
- (NSDictionary *)settingsForSticker:(NSString *)stickerSlug inPack:(NSString *)packSlug;

/**
 For setting all filter settings at once
 
 @param combinedSettings      a dictionary with the following structure
 
    @{
        @"pack-slug.filter-slug.setting_key": @"setting_value",
        @"pack-slug2.filter-slug2.setting_key2": @"setting_value"
     }
 
 e.g. 
  
    @{
        @"pink.summer.locked": @YES,
        @"pink.summer.unlock_message": @"You need 1,000 PINK points to unlock this filter. Play games to earn your points!"
     }
 
 @warning booleans in the dictionary must be objC objects rather than strings. e.g. use @YES rather than @"true".
 
 */
- (void)setFilterSettings:(NSDictionary *)combinedSettings;

/**
 @param combinedSettings    a dictionary following the same structure as the filter settings
 */
- (void)setStickerSettings:(NSDictionary *)combinedSettings;

#endif

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


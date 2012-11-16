//
//  SnaprKit.h
//  SnaprKit
//
//  Copyright (c) 2012 Snapr. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * SNInvalidConfigurationException;

@protocol SnaprKitDelegate;

/**
 * SnaprKit Configuration Singleton
 */
@interface SnaprKit : NSObject

@property (nonatomic, assign) id<SnaprKitDelegate> delegate;

/**
 The HTML pages are contained within a .bundle file, stored within the application's resources.
 You are required to customize this name if you want to override any of the project's strings.
 
 @return Defaults to "SnaprKit"
 */
@property (nonatomic, copy) NSString *customBundleName;

/**
 A loading view is presented before the HTML page completes its initial render.
 
 Place a 320x480 `LoadingView.png` and 640x960 `LoadingView@2x.png` file into the application's resources to be used as background for loading view
 A spinner graphic can be overlaid over this graphic
 
 @return Defaults to YES
 */
@property (nonatomic, assign) BOOL showLoadingSpinner;

/**
 SnaprKit will load all webview links that are not in the HTML bundle in a modal view.
 This allows the user to close it if they encounter an unexpected problem.
 
 If you want to ignore presenting a URL in a modal view, assign an array of domain strings to this list, e.g
 
 @[@"apple.com", @"ebay.com"]
 
 */
@property (nonatomic, retain) NSArray *ignoreModalWebViewOnDomains;

/**
 Change between developer and live mode.
 
 The uploads will go to either https://sna.pr (live) or http://dev.sna.pr (dev).
 A query parameter `environment=dev` or `environment=live` will be sent to the web view on page load.
 
 @return Defaults to YES.
 */
@property (nonatomic, assign) BOOL isDevMode;

/**
 Enables logging statements within the SnaprKit code, to help follow process flow.
 
 @return Defaults to NO
 */
@property (nonatomic, assign) BOOL debugLogging;

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
@property (retain, nonatomic, readonly) NSMutableArray *filterPacks;

/**
 Array of SNStickerPack Objects
 */
@property (retain, nonatomic, readonly) NSMutableArray *stickerPacks;

/**
 Assign an Array of Effect Constants. Typically these are defined as extern NSString* in a header file.
 */
@property (nonatomic, retain) NSArray *effectConstants;

/**
 Configuration for the effects.
 
 Each key begins with an Effect Constant (matching the effectConstants property), followed by a "." then the subkey name.
 
 @{@"PinkSummerEffect.locked" : @"You need 1,000 PINK points to unlock this filter."}
 
 */
@property (nonatomic, retain) NSDictionary *effectsConfiguration;

/**
 If the `CameraPlusIntegrationAPI.framework` has been included, and dependent libraries have been linked in your project.
 
 @return Defaults to NO
 */
@property (nonatomic, assign) BOOL cameraPlusAPIAvailable;

/**
 The callback URL scheme that your app has registered in your Info.plist, that Camera+ will use to return to your app.
 
 @return Defaults to the containing app's bundle identifier
 */
@property (nonatomic, copy) NSString *cameraPlusCallbackURLScheme;

/**
 If the libAviarySDK.a and resources have been included, and dependent libraries have been linked in your project.
 
 @return Defaults to NO
 */
@property (nonatomic, assign) BOOL aviarySDKAvailable;

/**
 You can provide a custom view to use as an overlay overtop the standard UIImagePicker.
 
 Auto Focus, zoom, front/back camera switching will still be available.
 */
@property (nonatomic, retain) UIView *cameraOverlayViewPortrait;

/**
 You can provide a custom view to use as an overlay overtop the standard UIImagePicker.
 
 Auto Focus, zoom, front/back camera switching will still be available.
 */
@property (nonatomic, retain) UIView *cameraOverlayViewLandscape;

/**
 Crop images to a square?
 
 @return Defaults to NO
 */
@property (nonatomic, assign) BOOL cropToSquare;

/**
 Aspect ratio to crop the images to.
 
 e.g 0.75 = 4:3
 */
@property (nonatomic, assign) CGFloat cropImagesAspectRatio;

/**
 Specifies the size of the the larger of either the width or height.
 Set to 0 to not apply any resizing.
 
 @return Defaults to 1600
 */
@property (nonatomic, assign) NSInteger maximumDimensionOfImage;

/**
 Exported JPEG Quality, Value from 0-1
 
 @return Defaults to 0.8
 */
@property (nonatomic, assign) CGFloat   jpegQuality;

/**
 Factory Method
 
 Assign your configuration options once to this Singleton instance, which will remain alive for the lifetime of your application.
 */
+ (SnaprKit *)sharedKit;

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


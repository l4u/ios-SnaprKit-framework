//
//  SNViewController.h
//  SnaprKit
//
//  Copyright (c) 2012 Snapr. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 * SnaprKit View Controller
 */
@interface SNViewController : UIViewController

/**
 Reloads the web view.
 
 For example once user credentials have been set using `[SnaprKit setUsername:accessToken:]`
 */
- (void)reloadPage;

/**
 Request a page to load in the web view.
 
 @param page the html filename
 
 @example `index.html` or `index.html#/connect/`
 */
- (void)loadPage:(NSString *)page;

/**
 Returns the absolute string for the URL of the current page in the web view.
 */
@property (nonatomic, readonly) NSString *currentPage;

/**
 Used for Camera+ Callbacks, Facebook login callbacks, and Smart App Banners
 
 Forward the URL object in your Application delegate's `- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url` or `- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation`
 
 */
- (BOOL)handleOpenURL:(NSURL *)url;


/**
 Used for Facebook SDK callback cleanup
 
 Call this method from within your Application Delegate's `- (void)applicationDidBecomeActive:(UIApplication *)application` method
 
 */
- (void)handleDidBecomeActive;


/** 
 Used for Facebook SDK session closing 
 
 Call this method from within your Application Delegate's `- (void)applicationWillTerminate:(UIApplication *)application` method
 
 */
- (void)handleWillTerminate;

@end

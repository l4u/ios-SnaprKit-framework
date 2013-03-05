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
 Used for Camera+ Callbacks, and Smart App Banners
 
 Forward your Application delegate's implementation of this method to this method.
 
 */
- (BOOL)handleOpenURL:(NSURL *)url;

@end

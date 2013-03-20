SnaprKit-framework
==================

SnaprKit iOS framework

# Framework Description
There are 2 frameworks:

* `SnaprKit.framework` – This just includes the core app for uploading images to Snapr
* `SnaprKitFX.framework` – This includes the core app plus the filter/sticker effects view.

## Cocoapods SnaprKit Installation

* Create a `Podfile` at the root of your project, and reference either the `SnaprKit` or `SnaprKitFX` pod at the git URL, and the appropriate commit hash.

```ruby
platform :ios, '5.0'

pod 'SnaprKitFX', :git => 'https://github.com/Snapr/ios-SnaprKit-framework', :commit => 'bb28ba8164e3695ec0a5a2e9ac0b77c04cefc993'
```

* Run `pod install`

## Manual SnaprKit Installation
The following items only apply if you don't use the pod.

* Drag the the framework into your project. Ensure you are linking against it in your target's build phase.

### Required Libraries
In your Target's Build Phases, link the Binary with the following Libraries:

#### Core SnaprKit.framework/SnaprEffectsKit.framework Libraries
* Foundation.framework
* UIKit.framework
* CFNetwork.framework
* SystemConfiguration.framework
* MobileCoreServices.framework
* CoreGraphics.framework
* libz.dylib
* libxml2.2.dylib
* ImageIO.framework
* AssetsLibrary.framework
* CoreLocation.framework
* Security.framework

#### Additional Libraries for SnaprEffectsKit.framework
* CoreMedia.framework
* CoreVideo.framework
* AVFoundation.framework
* OpenGLES.framework
* QuartzCore.framework

#### If including Aviary:
* Accelerate.framework
* StoreKit.framework
* libsqlite3.dylib
* CoreData.framework

#### Extra Build Settings:
* "Other Linker Flags": `-ObjC`, `-all_load`
  
## Resources
* You will need to copy `SnaprKitResources.bundle` into your project, and ensure it is included in your target's "Copy Bundle Resources" build phase.
* You will need a `SnaprKitHTML.bundle` in your project, which includes the project's HTML.

## Facebook Integration
Native Facebook integration is optional. SnaprKit will determine if if the Facebook SDK is available and configured at runtime, and use it if possible. It will fall back to an in-app auth flow if not present.

The project supports FacebookSDK.framework v3.2. 
### Manual Facebook SDK Installation
* Download from [here](https://developers.facebook.com/resources/facebook-ios-sdk-3.2.pkg)
* Follow the project configuration guide [here](https://developers.facebook.com/docs/getting-started/facebook-sdk-for-ios/)

### Cocoapods Facebook SDK Installation

```ruby
	pod 'Facebook-iOS-SDK', '3.2'
```

### Facebook Integration Configuration
In the app's main Info.plist, you will need to add two values which include the Facebook App ID.

| Key | Type | Value |
| --- | ---- | ------|
| FacebookAppID | String | e.g. "151738444987320" |
| URL Types | Array | URL Types Child Item |
| URL Types Child Item | Dictionary | URL Schemes Child Array |
| URL Schemes Child Array | Array | URL Scheme Child Item |
| URL Scheme Child Item | String | "fb" + App ID, e.g fb151738444987320 |

![FacebookAppID Config](https://raw.github.com/snapr/ios-SnaprKit-framework/master/Screenshots/FacebookAppID.png)

![URL Types Config](https://raw.github.com/snapr/ios-SnaprKit-framework/master/Screenshots/URLTypes.png)

## Usage:
Import the main header:
```#import <SnaprKit/SnaprKit.h>``` or ```#import <SnaprKitFX/SnaprKitFX.h>```

##### In your application delegate:
If you are making use of the Camera+ Integration API, you will need to forward your application delegate's ```application:handleOpenURL:``` or ```application:openURL:sourceApplication:annotation:``` method to the Snapr view controller instance. e.g. 

```objc
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
    return [self.vc handleOpenURL:url];
}
```

You can of course always add some of your own handles first and then pass it on to SnaprKit if it's not a URL scheme you accept.

##### Presenting Snapr:
Create an instance of SNViewController as you would any other view controller - 

```objc
SNViewController *snaprViewController = [[SNViewController] alloc] init];
```
You can then present it modally, add it to a tab bar, or use it as your application's root view controller. Any instance of this class will use the settings configured in SnaprKit.plist / on the shared SnaprKitConfig instance. 

##### Callbacks:
Conform to the `SnaprKitDelegate` protocol by assigning a class as a delegate to the shared snaprkit instance:
```SnaprKitConfig.sharedInstance.delegate = self;```
If you have any links/javascript in your bundle that requests ```snaprkit-parent://``` URLs, they will be forwarded to the delegate via the method:

```objc
- (void)snaprKitParentURLWasCalled:(NSURL *)url;
```

## Configuration Options
To customize the default behavior, create a file named `SnaprKit.plist` in your project, and override any of the below keys:

| Key                           | Type         | Default            | Description
|-------------------------------|--------------|--------------------| --------------------| 
| DevMode                       | Boolean      | YES                | Dev or Live server |
| DebugLogging                  | Boolean      | NO                 | Log activity to console |
| ShowLoadingSpinner            | Boolean      | YES                | Initial loading spinner before HTML render |
| CropImagesAspectRatio         | Number       | 0 = No Cropping    | 1 = Square; 0.75 = 4:3 |
| JPEGQuality                   | Number       | 0.8                | Number between 0 and 1 |
| MaximumDimensionOfImage       | Number       | 0 = No Resizing    | The size in pixels of the the larger of either the width or height |
| IgnoreModalWebViewOnDomains   | Array        |                    | Assign an array of domain strings to whitelist to this property. |
| BadgeApplicationIcon          | Boolean      | YES                | Show pending upload count as app badge |
| ShowFiltersFirstInEffectsView | Boolean      | YES                | Show filters before stickers in effects view |

## Image Overrides
Replace any of the images in `SnaprKitResources.bundle` with new files.

## String Overrides
Override any values in the localized `SnaprKit.strings` files, e.g English strings are at `SnaprKitResources.bundle/en.lproj/SnaprKit.strings`

#### Optional External components
Whether the Camera+ API, and/or the Aviary Effects SDK is included with your project, and you want to provide access to them.

| Key                           | Type         | Default            | Description
|-------------------------------|--------------|--------------------| --------------------| 
| CameraPlusCallbackURLScheme   | String       | App's Bundle ID    | Used when returning from Camera+ |

## Web View Configuration Options

The following properties of UIWebView can be configured in `SnaprKit.plist`

| Key                           | Type         | Default            | Description
|-------------------------------|--------------|--------------------| --------------------| 
| WebViewBounce                 | Boolean      | NO                 | Whether the webview's scrollview bounces |
| WebViewDetectDataTypes        | Boolean      | NO                 | Detect phone/address/calendar events in webview |
| WebViewSuppressesIncrementalRendering | Boolean | YES             | Controls the suppressesIncrementalRendering property of UIWebView if available |
| WebViewScalesPagesToFit       | Boolean      | NO                 | Controls the scalesPageToFit property of UIWebView |

#### Loading Web Content
The methods below are defined on SNViewController, and are related to the web view.

```objc
- (void)loadPage:(NSString *)page
```
Call this method to link directly to a page within the bundle from your native code.

```objc
- (void)reloadPage
```
Not generally needed, but maybe in a situation where you modify properties on the SnaprKitConfig instance (e.g User Credentials) and then need to reload what page is showing.

### Class Documentation
An Xcode docset should be automatically installed if you install SnaprKit from the pod. You can also view the class documentation online [here](http://snapr.github.com/ios-SnaprKit-framework/)

Pod::Spec.new do |s|
  s.name         = 'SnaprKitFX'
  s.version      = '3.0'
  s.summary      = 'Pod for easily integrating SnaprKit into your iOS app'
  s.homepage     = 'https://github.com/Snapr/ios-SnaprKit-framework'
  s.source       = { 
    :git => 'https://github.com/Snapr/ios-SnaprKit-framework.git'
  }
  s.platform     = :ios, '5.0'
  s.public_header_files = 'SnaprKitFX.framework/Headers'
  s.preserve_paths = 'SnaprKitFX.framework'
  
  s.xcconfig =  { 
    'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/SnaprKitFX"',
    'HEADER_SEARCH_PATHS' => '"$(SDKROOT)/usr/include/libxml2"'
  }
  s.frameworks  = 'SnaprKitFX', 'Foundation', 'UIKit', 'CFNetwork', 'SystemConfiguration', 'MobileCoreServices', 'CoreGraphics', 'ImageIO', 'AssetsLibrary', 'CoreLocation', 'Security', 'CoreMedia', 'CoreVideo', 'AVFoundation', 'OpenGLES', 'QuartzCore'
  s.libraries = 'z', 'xml2'
end

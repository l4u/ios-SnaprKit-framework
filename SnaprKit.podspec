Pod::Spec.new do |s|
  s.name         = "SnaprKit"
  s.version      = "1.0"
  s.summary      = "Pod for easily integrating SnaprKit into your iOS app"
  s.homepage     = "https://github.com/Snapr/SnaprKit"
  s.source       = { 
    :git => "https://github.com/Snapr/SnaprKit-framework.git",
    :tag => '0.0.1'
  }
  s.platform     = :ios, '4.3'
  s.public_header_files = 'SnaprKit.embeddedframework/SnaprKit.framework/Headers'
  s.preserve_paths = "SnaprKit.embeddedframework"
  
  s.xcconfig =  { 
    'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/SnaprKit/SnaprKit.embeddedframework/"',
    'HEADER_SEARCH_PATHS' => '"$(SDKROOT)/usr/include/libxml2"'
  }
  s.frameworks  = 'SnaprKit', 'CFNetwork', 'SystemConfiguration', 'MobileCoreServices', 'CoreGraphics', 'ImageIO', 'AssetsLibrary', 'CoreLocation', 'CoreMedia', 'CoreVideo', 'AVFoundation', 'OpenGLES', 'QuartzCore'
  s.libraries = 'z', 'xml2'
end

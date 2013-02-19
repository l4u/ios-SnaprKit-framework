//
//  ImageResizer.h
//  Flickr
//
//  Created by Karl von Randow on 21/03/08.
//  Copyright 2008 __XKCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

extern CGSize ResizeSizeToMaxSize(CGSize aSize, CGSize maxSize);
extern CGSize ResizeSizeToMaxSizeWithCrop(CGSize aSize, CGSize maxSize, BOOL crop);
extern CGRect RectToCenterSizeWithinMaxSize(CGSize aSize, CGSize maxSize);

@interface UIImage (Resizing)

- (UIImage *)resizedImageWithMaxWidth:(CGFloat)maxWidth maxHeight:(CGFloat)maxHeight;
- (UIImage *)croppedImageWithWidth:(CGFloat)maxWidth height:(CGFloat)maxHeight;
- (UIImage *)resizedImageWithWidth:(CGFloat)maxWidth height:(CGFloat)maxHeight crop:(BOOL)crop;
- (UIImage *)resizedImageWithWidth:(size_t)width height:(size_t)height scale:(CGFloat)scale crop:(BOOL)crop;

@end

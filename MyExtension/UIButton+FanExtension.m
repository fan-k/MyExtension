//
//  UIButton+FanExtension.m
//  MyExtension
//
//  Created by 樊康鹏 on 16/8/24.
//  Copyright © 2016年 FanKaren. All rights reserved.
//

#import "UIButton+FanExtension.h"
#import "UIColor+FanExtension.h"
#import "FanDefine.h"
#import "UIView+FanExtension.h"
@implementation UIButton (FanExtension)
/*!
 * 设置按钮正常状态下的图片
 */
- (void)setNormalImageName:(NSString *)imageName {
    [self setImage:FImageWithName(imageName) forState:UIControlStateNormal];
}

- (void)setNormalImage:(UIImage *)image {
    [self setImage:image forState:UIControlStateNormal];
}

- (void)setNormalImageWithColor:(UIColor *)color {
    [self setImage:[UIColor imageWithColor:color] forState:UIControlStateNormal];
}

- (void)setNormalBackgroundImageWithColor:(UIColor *)color {
    [self setBackgroundImage:[UIColor imageWithColor:color] forState:UIControlStateNormal];
}

/*!
 * 设置按钮Hightlighted状态下的图片
 */
- (void)setHightlightedImageName:(NSString *)imageName {
    [self setImage:FImageWithName(imageName) forState:UIControlStateHighlighted];
}

- (void)setHightlightedImage:(UIImage *)image {
    [self setImage:image forState:UIControlStateHighlighted];
}

- (void)setHightlightedImageWithColor:(UIColor *)color {
    [self setImage:[UIColor imageWithColor:color] forState:UIControlStateHighlighted];
}

- (void)setHightlightedBackgroundImageWithColor:(UIColor *)color {
    [self setBackgroundImage:[UIColor imageWithColor:color] forState:UIControlStateHighlighted];
}

/*!
 * 设置按钮Selected状态下的图片
 */
- (void)setSelectedImageName:(NSString *)imageName {
    [self setImage:FImageWithName(imageName) forState:UIControlStateSelected];
}

- (void)setSelectedImage:(UIImage *)image {
    [self setImage:image forState:UIControlStateSelected];
}

- (void)setSelectedImageWithColor:(UIColor *)color {
    [self setImage:[UIColor imageWithColor:color] forState:UIControlStateSelected];
}

- (void)setSelectedBackgroundImageWithColor:(UIColor *)color {
    [self setBackgroundImage:[UIColor imageWithColor:color] forState:UIControlStateSelected];
}

- (void)setNormal:(UIColor *)color hightlighted:(UIColor *)hgColor {
    [self setNormalImageWithColor:color];
    [self setHightlightedImageWithColor:hgColor];
}

- (void)setNormal:(UIColor *)color selected:(UIColor *)selColor {
    [self setNormalImageWithColor:color];
    [self setSelectedImageWithColor:selColor];
}

- (void)setNormal:(UIColor *)color hightlighted:(UIColor *)hgColor selected:(UIColor *)selColor {
    [self setNormal:color hightlighted:hgColor];
    [self setSelectedImageWithColor:selColor];
}

- (void)setBackgroundNormal:(UIColor *)color backgroundHightlighted:(UIColor *)hgColor {
    [self setNormalBackgroundImageWithColor:color];
    [self setHightlightedBackgroundImageWithColor:hgColor];
}

/*!
 * 设置按钮正常状态下的标题
 */
- (void)setNormalTitle:(NSString *)title {
    [self setTitle:title forState:UIControlStateNormal];
}

- (void)setHighlightedTitle:(NSString *)title {
    [self setTitle:title forState:UIControlStateHighlighted];
}

- (void)setSelectedTitle:(NSString *)title {
    [self setTitle:title forState:UIControlStateSelected];
}

- (void)setNormalTitleColor:(UIColor *)titleColor {
    [self setTitleColor:titleColor forState:UIControlStateNormal];
}

- (void)setHighlightedTitleColor:(UIColor *)titleColor {
    [self setTitleColor:titleColor forState:UIControlStateHighlighted];
}

- (void)setSelectedTitleColor:(UIColor *)titleColor {
    [self setTitleColor:titleColor forState:UIControlStateSelected];
}

- (void)setNormalTitle:(NSString *)title textColor:(UIColor *)color {
    [self setNormalTitle:title];
    [self setNormalTitleColor:color];
}

- (void)setHighlightedTitle:(NSString *)title textColor:(UIColor *)color {
    [self setHighlightedTitle:title];
    [self setHighlightedTitleColor:color];
}

- (void)setSelectedTitle:(NSString *)title textColor:(UIColor *)color {
    [self setSelectedTitle:title];
    [self setSelectedTitleColor:color];
}

/*!
 * 设置按钮状态下的字体大小
 */
- (void)setFontSize:(CGFloat)fontSize {
    self.titleLabel.font = DefaultFontSize(fontSize);
}

- (void)setBoldFontSize:(CGFloat)boldFontSize {
    self.titleLabel.font = DefaultBoldFontSize(boldFontSize);
}

- (void)setNormalImageName:(NSString *)imageName title:(NSString *)title isImageLeft:(BOOL)isLeft {
    [self setNormalImageName:imageName];
    [self setNormalTitle:title];
    
    if (isLeft) {
        self.imageEdgeInsets = UIEdgeInsetsMake(0, 10, 0, -10);
        self.titleEdgeInsets = UIEdgeInsetsMake(0, 20, 0, -20);
    } else {
        CGFloat w = self.width;
        CGFloat imgW = self.imageView.image.size.width;
        self.imageEdgeInsets = UIEdgeInsetsMake(0, w - imgW, 0, -10 + imgW);
        self.titleEdgeInsets = UIEdgeInsetsMake(0, -15, 0, 15);
    }
}
@end

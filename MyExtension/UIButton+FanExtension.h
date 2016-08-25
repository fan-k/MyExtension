//
//  UIButton+FanExtension.h
//  MyExtension
//
//  Created by 樊康鹏 on 16/8/24.
//  Copyright © 2016年 FanKaren. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIButton (FanExtension)
/*!
 * 设置按钮正常状态下的图片
 */
- (void)setNormalImageName:(NSString *)imageName;
- (void)setNormalImage:(UIImage *)image;
- (void)setNormalImageWithColor:(UIColor *)color;
- (void)setNormalBackgroundImageWithColor:(UIColor *)color;

/*!
 * 设置按钮Hightlighted状态下的图片
 */
- (void)setHightlightedImageName:(NSString *)imageName;
- (void)setHightlightedImage:(UIImage *)image;
- (void)setHightlightedBackgroundImageWithColor:(UIColor *)color;

/*!
 * 设置按钮Selected状态下的图片
 */
- (void)setSelectedImageName:(NSString *)imageName;
- (void)setSelectedImage:(UIImage *)image;
- (void)setSelectedImageWithColor:(UIColor *)color;
- (void)setSelectedBackgroundImageWithColor:(UIColor *)color;

/*!
 * 设置按钮状态下的图片
 */
- (void)setNormal:(UIColor *)color hightlighted:(UIColor *)hgColor;
- (void)setBackgroundNormal:(UIColor *)color backgroundHightlighted:(UIColor *)hgColor;
- (void)setNormal:(UIColor *)color selected:(UIColor *)selColor;
- (void)setNormal:(UIColor *)color hightlighted:(UIColor *)hgColor selected:(UIColor *)selColor;

/*!
 * 设置按钮状态下的标题
 */
- (void)setNormalTitle:(NSString *)title;
- (void)setHighlightedTitle:(NSString *)title;
- (void)setSelectedTitle:(NSString *)title;

/*!
 * 设置按钮状态下的标题颜色
 */
- (void)setNormalTitleColor:(UIColor *)titleColor;
- (void)setHighlightedTitleColor:(UIColor *)titleColor;
- (void)setSelectedTitleColor:(UIColor *)titleColor;

- (void)setNormalTitle:(NSString *)title textColor:(UIColor *)color;
- (void)setHighlightedTitle:(NSString *)title textColor:(UIColor *)color;
- (void)setSelectedTitle:(NSString *)title textColor:(UIColor *)color;

/*!
 * 设置按钮状态下的字体大小
 */
- (void)setFontSize:(CGFloat)fontSize;
- (void)setBoldFontSize:(CGFloat)boldFontSize;

- (void)setNormalImageName:(NSString *)imageName title:(NSString *)title isImageLeft:(BOOL)isLeft;
@end

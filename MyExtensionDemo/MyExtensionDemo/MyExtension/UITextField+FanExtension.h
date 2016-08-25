//
//  UITextField+FanExtension.h
//  MyExtension
//
//  Created by 樊康鹏 on 16/8/24.
//  Copyright © 2016年 FanKaren. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITextField (FanExtension)
/**
 *  设置光标位置
 *
 *  @param originx 光标起始点
 */
- (void)setCursorOnrign:(CGFloat )originx;
/**
 * 设置占位符的文字颜色
 *
 * @param placeholderColor 新颜色
 */
- (void)setPlaceholderColor:(UIColor *)placeholderColor;

/**
 * 设置占位符的文字字体
 *
 * @param placeholderFont 新字体
 */
- (void)setPlaceholderFont:(UIFont *)placeholderFont;
@end

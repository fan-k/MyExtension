//
//  UIAlertView+FanExtension.h
//  MyExtension
//
//  Created by 樊康鹏 on 16/8/24.
//  Copyright © 2016年 FanKaren. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIAlertView (FanExtension)
/*!
 * @brief 默认会带有确定和取消按钮
 * @param message 标题
 */
+ (UIAlertView *)showWithMessage:(NSString *)message;

/*!
 * @brief 默认会带有确定和取消按钮，需要标题和内容参数
 * @param title 标题
 * @param message 内容
 */
+ (UIAlertView *)showWithTitle:(NSString *)title message:(NSString *)message;

/*!
 * @brief 默认会带有确定和取消按钮，需要标题和内容参数
 * @param title 标题
 * @param message 内容
 * @param delegate 代理
 */
+ (UIAlertView *)showWithTitle:(NSString *)title message:(NSString *)message delegate:(id)delegate;

/*!
 * @brief 需要标题和内容参数,确定和取消按钮标题
 * @param title 标题
 * @param message 内容
 * @param okButtonTitle 确定标题
 */
+ (UIAlertView *)showWithTitle:(NSString *)title
                       message:(NSString *)message
                      okButton:(NSString *)okButtonTitle
                  cancelButton:(NSString *)cancelButtonTitle;

/*!
 * @brief 需要标题和内容参数，代理，确定和取消按钮标题
 * @param title 标题
 * @param message 内容
 * @param delegate 代理
 */
+ (UIAlertView *)showWithTitle:(NSString *)title
                       message:(NSString *)message
                      delegate:(id)delegate
                      okButton:(NSString *)okButtonTitle
                  cancelButton:(NSString *)cancelButtonTitle;
@end

//
//  UIAlertView+FanExtension.m
//  MyExtension
//
//  Created by 樊康鹏 on 16/8/24.
//  Copyright © 2016年 FanKaren. All rights reserved.
//

#import "UIAlertView+FanExtension.h"
#import "FanDefine.h"
#define kOkButtonDefaultTitle     @"确定"
#define kCancelButtonDefaultTitle @"取消"
@implementation UIAlertView (FanExtension)
+ (UIAlertView *)showWithMessage:(NSString *)message {
    return [self showWithTitle:nil message:message];
}

+ (UIAlertView *)showWithTitle:(NSString *)title message:(NSString *)message {
    return [self showWithTitle:title message:message delegate:nil];
}

+ (UIAlertView *)showWithTitle:(NSString *)title message:(NSString *)message delegate:(id)delegate {
    return [self showWithTitle:title
                       message:message
                      okButton:kOkButtonDefaultTitle
                  cancelButton:kCancelButtonDefaultTitle];
}

+ (UIAlertView *)showWithTitle:(NSString *)title
                       message:(NSString *)message
                      okButton:(NSString *)okButtonTitle
                  cancelButton:(NSString *)cancelButtonTitle {
    return [self showWithTitle:title
                       message:message
                      delegate:nil
                      okButton:okButtonTitle
                  cancelButton:cancelButtonTitle];
}

+ (UIAlertView *)showWithTitle:(NSString *)title
                       message:(NSString *)message
                      delegate:(id)delegate
                      okButton:(NSString *)okButtonTitle
                  cancelButton:(NSString *)cancelButtonTitle {
    __block UIAlertView *alertView = nil;
    
    dispatch_async(FGlobalThread, ^{
        alertView =  [[UIAlertView alloc] initWithTitle:title
                                                message:message
                                               delegate:delegate
                                      cancelButtonTitle:cancelButtonTitle
                                      otherButtonTitles:okButtonTitle, nil];
        dispatch_async(FMainThread, ^{
            [alertView show];
        });
    });
    return alertView;
}
@end

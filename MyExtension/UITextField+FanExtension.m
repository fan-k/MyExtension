//
//  UITextField+FanExtension.m
//  MyExtension
//
//  Created by 樊康鹏 on 16/8/24.
//  Copyright © 2016年 FanKaren. All rights reserved.
//

#import "UITextField+FanExtension.h"

@implementation UITextField (FanExtension)
- (void)setCursorOnrign:(CGFloat)originx
{
    UIView * leftView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, originx, self.frame.size.height)];
    [leftView setBackgroundColor:[UIColor clearColor]];
    self.leftView = leftView;
}
- (void)setPlaceholderColor:(UIColor *)placeholderColor {
    [self setValue:placeholderColor forKeyPath:@"_placeholderLabel.textColor"];
}

- (void)setPlaceholderFont:(UIFont *)placeholderFont {
    [self setValue:placeholderFont forKeyPath:@"_placeholderLabel.font"];
}
@end

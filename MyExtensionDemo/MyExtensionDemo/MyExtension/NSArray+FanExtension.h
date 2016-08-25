//
//  NSArray+FanExtension.h
//  MyExtension
//
//  Created by 樊康鹏 on 16/8/24.
//  Copyright © 2016年 FanKaren. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (FanExtension)
/**
 *  如果index索引值下有元素，返回该元素，否则返回nil
 *
 *  @param index 索引
 *  @return 获取到的元素或者nil
 */
- (id)safeObjectAtIndex:(NSUInteger)index;

/**
 *  返回逆序排序的数组
 *
 *  @return 逆序排序的数组
 */
- (NSArray *)reversedArray;
+ (NSArray *)reversedArray:(NSArray *)array;

/**
 *  将数组转换成JSON字符串
 *
 *  @return JSON字符串或者nil（转换失败）
 */
- (NSString *)toJson;
+ (NSString *)toJson:(NSArray *)array;

/**
 * 判断数组中是否包含string
 *
 * @param string 待判断的字符串
 *
 * @return YES表示包含，NO表示不包含
 */
- (BOOL)isContainsString:(NSString *)string;
@end

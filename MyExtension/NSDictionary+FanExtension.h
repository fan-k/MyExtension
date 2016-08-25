//
//  NSDictionary+FanExtension.h
//  MyExtension
//
//  Created by 樊康鹏 on 16/8/24.
//  Copyright © 2016年 FanKaren. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (FanExtension)
/**
 *  处理字典中的空
 *
 *  @param obj obj
 *
 *  @return obj
 */
+ (id)changeType:(id)obj;
/*!
 * 把格式化的JSON格式的字符串转换成字典
 *
 * @param jsonString JSON格式的字符串
 * @return 返回字典
 */
+ (NSDictionary *)dictionaryWithJsonString:(NSString *)jsonString;

/*!
 * 获取JSON字符串
 *
 * @return 把字典转换成JSON串
 */
- (NSString *)jsonString;

/*!
 * 根据key获取值
 *
 * @return 如果存在，返回value，否则返回nil，表示不存在或者是空
 */
- (id)safeObjectForKey:(id<NSCopying>)aKey;

/*!
 * 根据key获取值
 *
 * @return 如果存在，返回value，否则返回0
 */
- (int)intValueForKey:(id)key;

/*!
 * 根据key获取值
 *
 * @return 如果存在，返回value，否则返回0.0
 */
- (double)doubleValueForKey:(id)key;

/*!
 * 根据key获取值
 *
 * @return 如果存在，返回value，否则返回0.0f
 */
- (float)floatValueForKey:(id)key;

/*!
 * 根据key获取值
 *
 * @return 如果存在，返回value，否则返回0
 */
- (NSInteger)integerValueForKey:(id)key;

/*!
 * 根据key获取值
 *
 * @return 如果存在，返回value，否则返回nil
 */
- (NSString *)stringValueForKey:(id)key;

/*!
 * 根据key获取值
 *
 * @return 如果存在，返回value，否则返回nil
 */
- (NSDictionary *)dictionaryValueForKey:(id)key;

/*!
 * 根据key获取值
 *
 * @return 如果存在，返回value，否则返回nil
 */
- (NSArray *)arrayValueForKey:(id)key;

/*!
 * 根据key获取值
 *
 * @return 如果存在，返回value，否则返回nil
 */
- (NSNumber *)numberValueForKey:(id)key;
@end

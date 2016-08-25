//
//  NSString+FanExtension.h
//  MyExtension
//
//  Created by 樊康鹏 on 16/8/24.
//  Copyright © 2016年 FanKaren. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (FanExtension)

/**
 *  生成MD5加密字符串
 *
 *  @return MD5加密后的字符串
 */
- (NSString *)md5;

/**
 *  生成SHA1/SHA256/SHA512加密字符串
 *
 *  @return SHA1/SHA256/SHA512加密字符串
 */
- (NSString *)SHA1;
- (NSString *)SHA256;
- (NSString *)SHA512;

/**
 *  对test进行AES算法加密
 *
 *  @param text 待加密的文本
 *  @param password 加密使用的密码，解密时会需要到此密码
 *
 *  @return AES加密后的字符串
 */
+ (NSString *)AESEncrypt:(NSString *)text password:(NSString *)password;

/**
 *  进行AES算法解密
 *
 *  @param base64EncodedString 待解密的文本
 *  @param password 加密时使用的密码
 *
 *  @return AES解密后的字符串
 */
+ (NSString *)AESDecrypt:(NSString *)base64EncodedString password:(NSString *)password;

/**
 * 把data转成base64字符串
 *
 * @param data 待转换的二进制数据
 * @param length 转换的长度范围
 *
 * @return 转换后的字符串
 */
+ (NSString *)base64StringFromData:(NSData *)data length:(NSUInteger)length;

/*!
 * @brief 获取网卡的MAC地址
 *
 * @return 网卡的MAC地址
 */
+ (NSString *)macAddress;

/*!
 *  将字符串转换成二进制数据后，再进行base64编码
 *
 *  @return 返回base64编码后的字符串
 */
- (NSString *)base64Encoding;
+ (NSString *)base64Encoding:(NSString *)text;

/*!
 *  将base64编码字符串还原成普通字符串
 *
 *  @return 普通字符串
 */
+ (NSString *)textWithBase64Encoding:(NSString *)base64Encoding;

/*!
 *  转换成data数据
 *
 *  @return data数据
 */
- (NSData *)toData;
+ (NSString *)toString:(NSData *)data;

/**
 *  判断是否是合格的邮箱格式
 *
 *  @return YES表示正确，NO表示不正确
 */
- (BOOL)isValidEmail;
+ (BOOL)isValidEmail:(NSString *)email;

/*!
 * @brief  验证是否是正确的手机号码格式
 *
 * @return YES表示是正确的手机号码格式，返回NO表示手机号码格式不正确
 */
- (BOOL)isValidPhone;
+ (BOOL)isValidPhone:(NSString *)phone;

/*!
 * @brief  验证是否是正确的固定电话号码格式
 *
 * @return YES表示是正确的固定电话号码格式，返回NO表示固话号码格式不正确
 */
- (BOOL)isValidTelNumber;
+ (BOOL)isValidTelNumber:(NSString *)telNumber;

/*!
 * @brief  验证是否是正确的18位身份证号码格式
 *
 * @return YES表示是正确的身份证号码格式，返回NO表示身份证号码格式不正确
 */
- (BOOL)isValidPersonID;
+ (BOOL)isValidPersonID:(NSString *)PID;

/*!
 * 去掉空格符号操作，分别是去掉左边的空格、去掉右边的空格、去掉两边的空格、去掉所有空格、去掉所有字母、
 * 去掉字符中中所有的指定的字符
 *
 * @return 处理后的字符串
 */
- (NSString *)trimLeft;
- (NSString *)trimRight;
- (NSString *)trim;
- (NSString *)trimAll;
- (NSString *)trimLetters;
- (NSString *)trimCharacter:(unichar)character;
- (NSString *)trimWhitespace;
- (NSUInteger)numberOfLines;

/*!
 * 判断是否只包含字母、数字、字母和数字
 *
 * @return YES，表示条件正确，否则返回NO
 */
- (BOOL)isOnlyLetters;
- (BOOL)isOnlyNumbers;
- (BOOL)isOnlyAlphaNumeric;

/*!
 * @brief 判断是否是空串/判断去掉两边的空格后是否是空串
 *
 * @return YES表示是空串，NO表示非空
 */
- (BOOL)isEmpty;
- (BOOL)isTrimEmpty;

/**
 * 转换成URL
 */
- (NSURL *)toURL;

/**
 * 把URL进行UTF8转码
 */
- (NSString *)URLEncode;

/*!
 * 过滤掉HTML标签
 *
 * @param html HTML内容
 * @param 返回喜欢去掉所有HTML标签后的字符串
 */
- (NSString *)filteredHtml;
+ (NSString *)filterHTML:(NSString *)html;

/*!
 * 添加前缀、后缀（不修改self）
 *
 * @param prefix-前缀 subfix-后缀
 * @param 返回添加后的字符串
 */
- (NSString *)addPrefix:(NSString *)prefix;
- (NSString *)addSubfix:(NSString *)subfix;

/*!
 * @brief  根据文件名返回文件的路径
 * @param  fileName 文件名(使用type参数，就不能加后缀)
 * @param  type     文件后缀名
 * @return 如果文件路径存在，则返回该文件路径，否则返回nil
 */
+ (NSString *)pathWithFileName:(NSString *)fileName;
+ (NSString *)pathWithFileName:(NSString *)fileName ofType:(NSString *)type;

/*!
 * @brief 获取Documents/tmp/Cache路径
 */
+ (NSString *)documentPath;
+ (NSString *)tmpPath;
+ (NSString *)cachePath;
@end

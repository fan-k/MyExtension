//
//  NSError+FanExtension.h
//  MyExtension
//
//  Created by 樊康鹏 on 16/8/24.
//  Copyright © 2016年 FanKaren. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonCryptor.h>
/**
 * 加密算法错误Error Domin
 */
extern NSString * const kCommonCryptoErrorDomain;
@interface NSError (FanExtension)


/**
 * 根据加密算法状态，生成错误对象
 */
+ (NSError *)errorWithCCCryptorStatus:(CCCryptorStatus)status;
@end

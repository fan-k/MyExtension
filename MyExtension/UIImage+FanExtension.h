//
//  UIImage+FanExtension.h
//  MyExtension
//
//  Created by 樊康鹏 on 16/8/24.
//  Copyright © 2016年 FanKaren. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (FanExtension)

/**
 * 把图片转换成base64编码的字符串
 */
- (NSString *)toBase64;

/*!
 * @brief 根据指定的Rect来截取图片，返回截取后的图片
 * @param rect 指定的Rect，如果大小超过图片大小，就会返回原图片
 * @return 返回截取后的图片
 */
- (UIImage *)subImageWithRect:(CGRect)rect;

/*!
 * @brief 把图片等比例缩放到指定的size
 * @param size 缩放后的图片的大小
 * @return 返回缩放后的图片
 */
- (UIImage *)scaleToSize:(CGSize)size;

/*!
 * @brief 根据指定的模式来压缩图片
 * @param contentMode 压缩模式
 * @param bounds      压缩到bounds
 * @param quality     压缩质量
 */
- (UIImage *)resizedImageWithContentMode:(UIViewContentMode)contentMode
                                  bounds:(CGSize)bounds
                    interpolationQuality:(CGInterpolationQuality)quality;

/*!
 * @brief 自动调整图片到目标大小
 * @param destImageSize 目标图片大小，单位是MB
 * @param quality     压缩质量
 */
- (UIImage *)resizedImageWithUncompressedSizeInMB:(CGFloat)destImageSize
                             interpolationQuality:(CGInterpolationQuality)quality;
- (UIImage *)imageByScalingToMaxSize:(UIImage *)sourceImage;
- (UIImage *)imageByScalingAndCroppingForSourceImage:(UIImage *)sourceImage targetSize:(CGSize)targetSize;


/**
 * 来自ImageEffects的方法，添加blur等效果
 */
- (UIImage *)applyLightEffect;
- (UIImage *)applyExtraLightEffect;
- (UIImage *)applyDarkEffect;
- (UIImage *)applyTintEffectWithColor:(UIColor *)tintColor;
- (UIImage *)applyBlurWithRadius:(CGFloat)blurRadius
                       tintColor:(UIColor *)tintColor
           saturationDeltaFactor:(CGFloat)saturationDeltaFactor
                       maskImage:(UIImage *)maskImage;

/**
 * 来自BlurredFrame的方法，添加部分blur等效果
 */
- (UIImage *)applyLightEffectAtFrame:(CGRect)frame;
- (UIImage *)applyExtraLightEffectAtFrame:(CGRect)frame;
- (UIImage *)applyDarkEffectAtFrame:(CGRect)frame;
- (UIImage *)applyTintEffectWithColor:(UIColor *)tintColor atFrame:(CGRect)frame;
- (UIImage *)applyBlurWithRadius:(CGFloat)blurRadius
                       tintColor:(UIColor *)tintColor
           saturationDeltaFactor:(CGFloat)saturationDeltaFactor
                       maskImage:(UIImage *)maskImage
                         atFrame:(CGRect)frame;
@end

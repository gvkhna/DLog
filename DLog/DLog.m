//
//  DLog.m
//  DLog
//
//  Created by Gaurav Khanna on 12/11/13.
//  Copyright (c) 2013 Gaurav Khanna. All rights reserved.
//

#if DEBUG

#import "DLog.h"
#import <objc/runtime.h>

@implementation DLog

#pragma mark - Objective C Runtime Data Type Descriptions

+ (NSString*)Selector:(SEL)selector {
    return NSStringFromSelector(selector);
}

+ (NSString*)Protocol:(Protocol*)protocol {
    return NSStringFromProtocol(protocol);
}

+ (NSString*)Class:(Class)class_val {
    return NSStringFromClass(class_val);
}

+ (NSString*)TypeEncoding:(id)value {
    return [DLog cTypeEncoding:(void*)value];
}

+ (const char *)cTypeString:(int)type {
    size_t bufferLimit = 256;
    char cIntEncoding[bufferLimit];
    snprintf(cIntEncoding, bufferLimit, "%d", type);
    return [[NSString stringWithCString:cIntEncoding encoding:NSUTF8StringEncoding] cStringUsingEncoding:NSUTF8StringEncoding];
}

+ (NSString*)cTypeEncoding:(void*)value {
    const char *encoding = @encode(typeof(value));

    if (strcmp(encoding, [DLog cTypeString:_C_INT])) {
        return @"int";
    } else if (strcmp(encoding, @encode(int *))) {
        return @"int*";
    } else if (strcmp(encoding, [DLog cTypeString:_C_FLT])) {
        return @"float";
    } else if (strcmp(encoding, @encode(float *))) {
        return @"float*";
    } else if (strcmp(encoding, [DLog cTypeString:_C_CHR])) {
        return @"char";
    } else if (strcmp(encoding, @encode(char *))) {
        return @"char*";
    } else if (strcmp(encoding, [DLog cTypeString:_C_BOOL])) {
        return @"BOOL";
    } else if (strcmp(encoding, @encode(BOOL *))) {
        return @"BOOL*";
    } else if (strcmp(encoding, [DLog cTypeString:_C_DBL])) {
        return @"double";
    } else if (strcmp(encoding, @encode(double *))) {
        return @"double*";
    } else if (strcmp(encoding, [DLog cTypeString:_C_VOID])) {
        return @"void";
    } else if (strcmp(encoding, @encode(void *))) {
        return @"void*";
    } else if (strcmp(encoding, [DLog cTypeString:_C_SHT])) {
        return @"short";
    } else if (strcmp(encoding, @encode(short *))) {
        return @"short*";
    } else if (strcmp(encoding, [DLog cTypeString:_C_LNG])) {
        return @"long";
    } else if (strcmp(encoding, @encode(long *))) {
        return @"long*";
    } else if (strcmp(encoding, [DLog cTypeString:_C_LNG_LNG])) {
        return @"long long";
    } else if (strcmp(encoding, @encode(long long *))) {
        return @"long long*";
    } else if (strcmp(encoding, [DLog cTypeString:_C_UCHR])) {
        return @"unsigned char";
    } else if (strcmp(encoding, @encode(unsigned char *))) {
        return @"unsigned char*";
    } else if (strcmp(encoding, [DLog cTypeString:_C_UINT])) {
        return @"unsigned int";
    } else if (strcmp(encoding, @encode(unsigned int *))) {
        return @"unsigned int*";
    } else if (strcmp(encoding, [DLog cTypeString:_C_USHT])) {
        return @"unsigned short";
    } else if (strcmp(encoding, @encode(unsigned short *))) {
        return @"unsigned short*";
    } else if (strcmp(encoding, [DLog cTypeString:_C_ULNG])) {
        return @"unsigned long";
    } else if (strcmp(encoding, @encode(unsigned long *))) {
        return @"unsigned long*";
    } else if (strcmp(encoding, [DLog cTypeString:_C_ULNG_LNG])) {
        return @"unsigned long long";
    } else if (strcmp(encoding, @encode(unsigned long long *))) {
        return @"unsigned long long*";
    } else if (strcmp(encoding, [DLog cTypeString:_C_CLASS])) {
        return @"Class";
    } else if (strcmp(encoding, [DLog cTypeString:_C_SEL])) {
        return @"SEL";
    } else if (strcmp(encoding, [DLog cTypeString:_C_ID])) {
        return @"id";
    } else if (strcmp(encoding, @encode(typeof(id*)))) {
        return @"id*";
    } else if (strcmp(encoding, "r^@")) {
        return @"&id";
    } else if (strcmp(encoding, [DLog cTypeString:_C_BFLD])) {
        return @"C-BitField-Type=b";
    } else if (strcmp(encoding, [DLog cTypeString:_C_UNDEF])) {
        return @"undef";
    } else if (strcmp(encoding, [DLog cTypeString:_C_PTR])) {
        return @"C-Pointer-Type=^";
    } else if (strcmp(encoding, [DLog cTypeString:_C_CHARPTR])) {
        return @"C-CharPointer-Type=*";
    } else if (strcmp(encoding, [DLog cTypeString:_C_ATOM])) {
        return @"atom";
    } else if (strcmp(encoding, [DLog cTypeString:_C_VECTOR])) {
        return @"vector";
    } else if (strcmp(encoding, [DLog cTypeString:_C_CONST])) {
        return @"const";
    } else if (strcmp(encoding, "n")) { // read objc runtime programming guide
        return @"in"; // protocol method encodings going forward
    } else if (strcmp(encoding, "N")) {
        return @"inout";
    } else if (strcmp(encoding, "o")) {
        return @"out";
    } else if (strcmp(encoding, "O")) {
        return @"bycopy";
    } else if (strcmp(encoding, "R")) {
        return @"byref";
    } else if(strcmp(encoding, "V")) {
        return @"oneway";
    } else { // return the original encoding string
        return [NSString stringWithCString:encoding encoding:NSUTF8StringEncoding];
    }
}

+ (NSString*)base64EncodedStringWithData:(NSData*)data {
    return [data base64EncodedStringWithOptions:0];
}

+ (NSString*)base64EncodedString64CharacterLineLengthWithData:(NSData*)data {
    return [data base64EncodedStringWithOptions:NSDataBase64Encoding64CharacterLineLength];
}

+ (NSString*)base64EncodedString76CharacterLineLengthWithData:(NSData*)data {
    return [data base64EncodedStringWithOptions:NSDataBase64Encoding76CharacterLineLength];
}

+ (NSString*)base64EncodedStringEndLineWithCarriageReturnWithData:(NSData*)data {
    return [data base64EncodedStringWithOptions:NSDataBase64EncodingEndLineWithCarriageReturn];
}

+ (NSString*)base64EncodedStringEndLineWithLineFeedWithData:(NSData*)data {
    return [data base64EncodedStringWithOptions:NSDataBase64EncodingEndLineWithLineFeed];
}

#pragma mark - Foundation Data Type Descriptions

+ (NSString*)NSRange:(NSRange)range {
    return NSStringFromRange(range);
}

#pragma mark - Core Geometry Data Type Descriptions

+ (NSString*)CGPoint:(CGPoint)point {
#if TARGET_OS_IPHONE || TARGET_OS_SIMULATOR
    return NSStringFromCGPoint(point);
#else
    return NSStringFromPoint(NSPointFromCGPoint(point));
#endif
}

+ (NSString*)CGSize:(CGSize)size {
#if TARGET_OS_IPHONE || TARGET_OS_SIMULATOR
    return NSStringFromCGSize(size);
#else
    return NSStringFromSize(NSSizeFromCGSize(size));
#endif
}

+ (NSString*)CGRect:(CGRect)rect {
#if TARGET_OS_IPHONE || TARGET_OS_SIMULATOR
    return NSStringFromCGRect(rect);
#else
    return NSStringFromRect(NSRectFromCGRect(rect)));
#endif
}

+ (NSString*)CATransform3D:(CATransform3D)transform {
    return [[NSValue valueWithCATransform3D:transform] description];
}

#if TARGET_OS_IPHONE || TARGET_OS_SIMULATOR

#pragma mark - iOS Data Type Descriptions

+ (NSString*)base64EncodedStringWithUIImage:(UIImage*)image {
    return [DLog base64EncodedStringWithData:UIImagePNGRepresentation(image)];
}

+ (NSString*)UIView:(UIView*)view {
    SEL recursiveDescriptionSEL = NSSelectorFromString(@"recursiveDescription");
    if ([view respondsToSelector:recursiveDescriptionSEL]) {
        IMP recursiveDescriptionIMP = [view methodForSelector:recursiveDescriptionSEL];
        NSString * (*recursiveDescriptionFunction)(id, SEL) = (void *)recursiveDescriptionIMP;
        return recursiveDescriptionFunction(view, recursiveDescriptionSEL);
    }
    return nil;
}

+ (NSData*)UIImage:(UIImage*)image {
    return UIImagePNGRepresentation(image);
}

+ (NSString*)UIOffset:(UIOffset)offset {
    return NSStringFromUIOffset(offset);
}

+ (NSString*)UIEdgeInsets:(UIEdgeInsets)edgeinsets {
    return NSStringFromUIEdgeInsets(edgeinsets);
}

+ (NSString*)CGAffineTransform:(CGAffineTransform)affinetransform {
    return NSStringFromCGAffineTransform(affinetransform);
}

+ (NSString*)UIGestureRecognizerState:(UIGestureRecognizerState)state {
    switch (state) {
        case UIGestureRecognizerStatePossible: {
            return @"UIGestureRecognizerStatePossible";
            break;
        }
        case UIGestureRecognizerStateBegan: {
            return @"UIGestureRecognizerStateBegan";
            break;
        }
        case UIGestureRecognizerStateChanged: {
            return @"UIGestureRecognizerStateChanged";
            break;
        }
        case UIGestureRecognizerStateCancelled: {
            return @"UIGestureRecognizerStateCancelled";
            break;
        }
        case UIGestureRecognizerStateFailed: {
            return @"UIGestureRecognizerStateFailed";
            break;
        }
        case UIGestureRecognizerStateRecognized: {
            if (state == UIGestureRecognizerStateEnded) {
                return @"UIGestureRecognizerStateEnded";
            }
            return @"UIGestureRecognizerStateRecognized";
            break;
        }
        default:
            return nil;
            break;
    }
}

+ (NSString*)NSIndexPath:(NSIndexPath*)indexPath {
    return [[indexPath description] stringByAppendingString:[NSString stringWithFormat:@"ITEM:%ld ROW:%ld SECTION:%ld", (long)indexPath.row, (long)indexPath.item, (long)indexPath.section]];
}

+ (void)performLowMemoryWarning {
    SEL sharedApplicationSEL = @selector(sharedApplication);
    SEL memoryWarningSEL = NSSelectorFromString(@"_performMemoryWarning");
    if ([UIApplication resolveClassMethod:sharedApplicationSEL]) {
        IMP sharedApplicationIMP = [UIApplication methodForSelector:sharedApplicationSEL];
        UIApplication * (*sharedApplicationFunction)(id, SEL) = (void *)sharedApplicationIMP;
        UIApplication *app = sharedApplicationFunction([UIApplication class], sharedApplicationSEL);
        if ([app respondsToSelector:memoryWarningSEL]) {
            IMP memoryWarningIMP = [UIApplication methodForSelector:memoryWarningSEL];
            void (*memoryWarningFunction)(id, SEL) = (void *)memoryWarningIMP;
            memoryWarningFunction(app, memoryWarningSEL);
        }
    }
}

#else

#pragma mark - Mac Data Type Descriptions

+ (NSString*)NSPoint:(NSPoint)point {
    return NSStringFromPoint(point);
}

+ (NSString*)NSSize:(NSSize)size {
    return NSStringFromSize(size);
}

+ (NSString*)NSRect:(NSRect)rect {
    return NSStringFromRect(rect);
}

+ (NSString*)NSHashTable:(NSHashTable*)hashtable {
    return NSStringFromHashTable(hashtable);
}

+ (NSString*)NSMapTable:(NSMapTable*)maptable {
    return NSStringFromMapTable(maptable);
}

#endif

#pragma mark - GLKit Data Type Descriptions

+ (NSString*)GLKMatrix2:(GLKMatrix2)matrix {
    return NSStringFromGLKMatrix2(matrix);
}

+ (NSString*)GLKMatrix3:(GLKMatrix3)matrix {
    return NSStringFromGLKMatrix3(matrix);
}

+ (NSString*)GLKMatrix4:(GLKMatrix4)matrix {
    return NSStringFromGLKMatrix4(matrix);
}

+ (NSString*)GLKVector2:(GLKVector2)vector {
    return NSStringFromGLKVector2(vector);
}

+ (NSString*)GLKVector3:(GLKVector3)vector {
    return NSStringFromGLKVector3(vector);
}

+ (NSString*)GLKVector4:(GLKVector4)vector {
    return NSStringFromGLKVector4(vector);
}

+ (NSString*)GLKQuaternion:(GLKQuaternion)quaternion {
    return NSStringFromGLKQuaternion(quaternion);
}

@end

#endif

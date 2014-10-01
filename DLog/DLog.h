//
//  DLog.h
//  DLog
//
//  Created by Gaurav Khanna on 11/18/13.
//  Copyright (c) 2014 Gaurav Khanna. All rights reserved.
//

#ifndef dlog_h
#define dlog_h

#ifdef __OBJC__

    #ifdef __DEBUG__
        #ifndef DEBUG
            #define DEBUG
        #endif
    #endif

    #if DEBUG
        #ifndef DEBUG
            #define DEBUG
        #endif
    #endif

    #ifdef DEBUG
        #ifndef DLOG
            #define DLOG
        #endif
    #endif

    #ifdef DLOG
        #import <objc/runtime.h>
        #import <Foundation/NSObjCRuntime.h>
        #import <Foundation/Foundation.h>
        #import <GLKit/GLKit.h>
        #if TARGET_OS_IPHONE || TARGET_OS_SIMULATOR
            #import <UIKit/UIKit.h>
        #endif

#pragma mark - Debugger Helper Class

@interface DLog : NSObject

+ (NSString*)Selector:(SEL)selector;
+ (NSString*)Protocol:(Protocol*)protocol;
+ (NSString*)Class:(Class)class_val;
+ (NSString*)TypeEncoding:(id)value;
+ (NSString*)cTypeEncoding:(void*)value;
+ (const char *)cTypeString:(int)type;

+ (NSString*)base64EncodedStringWithData:(NSData*)data;
+ (NSString*)base64EncodedString64CharacterLineLengthWithData:(NSData*)data;
+ (NSString*)base64EncodedString76CharacterLineLengthWithData:(NSData*)data;
+ (NSString*)base64EncodedStringEndLineWithCarriageReturnWithData:(NSData*)data;
+ (NSString*)base64EncodedStringEndLineWithLineFeedWithData:(NSData*)data;

+ (NSString*)NSRange:(NSRange)range;
+ (NSString*)CGPoint:(CGPoint)point;
+ (NSString*)CGSize:(CGSize)size;
+ (NSString*)CGRect:(CGRect)rect;
+ (NSString*)CATransform3D:(CATransform3D)transform;

#if TARGET_OS_IPHONE || TARGET_OS_SIMULATOR

+ (NSString*)base64EncodedStringWithUIImage:(UIImage*)image;

+ (NSString*)UIView:(UIView*)view;
+ (NSString*)UIImage:(UIImage*)image;
+ (NSString*)UIOffset:(UIOffset)offset;
+ (NSString*)UIEdgeInsets:(UIEdgeInsets)edgeinsets;
+ (NSString*)CGAffineTransform:(CGAffineTransform)cgaffinetransform;
+ (NSString*)UIGestureRecognizerState:(UIGestureRecognizerState)state;
+ (NSString*)NSIndexPath:(NSIndexPath*)indexPath;
+ (void)performLowMemoryWarning;

#else 

+ (NSString*)NSPoint:(NSPoint)point;
+ (NSString*)NSSize:(NSSize)size;
+ (NSString*)NSRect:(NSRect)rect;
+ (NSString*)NSHashTable:(NSHashTable*)hashtable;
+ (NSString*)NSMapTable:(NSMapTable*)maptable;

#endif

+ (NSString*)GLKMatrix2:(GLKMatrix2)matrix;
+ (NSString*)GLKMatrix3:(GLKMatrix3)matrix;
+ (NSString*)GLKMatrix4:(GLKMatrix4)matrix;
+ (NSString*)GLKVector2:(GLKVector2)vector;
+ (NSString*)GLKVector3:(GLKVector3)vector;
+ (NSString*)GLKVector4:(GLKVector4)vector;
+ (NSString*)GLKQuaternion:(GLKQuaternion)quaternion;

@end

        #ifndef DLOG_PREFIX
            #define DLOG_PREFIX DL
        #endif

        #define Q_(x) #x
        #define Q(x) Q_(x)
        #define PRE Q(DLOG_PREFIX)

#pragma mark - Logging Methods

        #define DLog(format, ...)           NSLog(@"%s:%@; ", PRE, [NSString stringWithFormat:format, ## __VA_ARGS__ ])
        #define DLogFunctionLine()          NSLog(@"%s:%s;%d;", PRE, __PRETTY_FUNCTION__, __LINE__)


        #define DLogObject(obj)             NSLog(@"%s:%s;%@;", PRE, #obj , obj)
        #define DLogNSObject(obj)           DLogObject(obj)
        #define DLogException(obj)          DLogObject([obj name]);DLogObject([obj reason]);DLogObject([obj callStackSymbols]);DLogObject([obj callStackReturnAddresses])
        #define DLogClass(val)              NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromClass(val))
        #define DLogSEL(val)                NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromSelector(val))
        #define DLogProtocol(val)           NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromProtocol(val))
        #define DLogPointer(val)            NSLog(@"%s:%s;%p;", PRE, #val, val)
        #define DLogTypeEncoding(val)       NSLog(@"%s:%s;%s;", PRE, #val, @encode(typeof(val)))
        #define DLogBytes(val)              NSLog(@"%s:%s;%@;", PRE, #val, [NSData dataWithBytes:&val length:sizeof(val)])
        #define DLogByteOrder()             NSLog(@"%s:%s;", PRE, ( NSHostByteOrder() ? "LittleEndian" : "BigEndian" ))

        #define DLogBOOL(val)               NSLog(@"%s:%s;%s;", PRE, #val, (val ? "YES" : "NO"))
        #define DLogNSRange(val)            NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromRange(val))
        #define DLogunichar(val)            NSLog(@"%s:%s;%C;", PRE, #val, val)

        #define DLogid(obj)                 DLogObject(obj)
        #define DLogCGFloat(val)            DLogfloat(val)

        #define DLogchar(val)               NSLog(@"%s:%s;%@;", PRE, #val, [NSNumber numberWithChar:val])
        #define DLogdouble(val)             NSLog(@"%s:%s;%@;", PRE, #val, [NSNumber numberWithDouble:val])
        #define DLogfloat(val)              NSLog(@"%s:%s;%@;", PRE, #val, [NSNumber numberWithFloat:val])
        #define DLogint(val)                NSLog(@"%s:%s;%@;", PRE, #val, [NSNumber numberWithInt:val])
        #define DLogNSInteger(val)          NSLog(@"%s:%s;%@;", PRE, #val, [NSNumber numberWithInteger:val])
        #define DLoglong(val)               NSLog(@"%s:%s;%@;", PRE, #val, [NSNumber numberWithLong:val])
        #define DLoglonglong(val)           NSLog(@"%s:%s;%@;", PRE, #val, [NSNumber numberWithLongLong:val])
        #define DLogshort(val)              NSLog(@"%s:%s;%@;", PRE, #val, [NSNumber numberWithShort:val])
        #define DLogunsignedchar(val)       NSLog(@"%s:%s;%@;", PRE, #val, [NSNumber numberWithUnsignedChar:val])
        #define DLogunsignedint(val)        NSLog(@"%s:%s;%@;", PRE, #val, [NSNumber numberWithUnsignedInt:val])
        #define DLogNSUInteger(val)         NSLog(@"%s:%s;%@;", PRE, #val, [NSNumber numberWithUnsignedInteger:val])
        #define DLogunsignedlong(val)       NSLog(@"%s:%s;%@;", PRE, #val, [NSNumber numberWithUnsignedLong:val])
        #define DLogunsignedlonglong(val)   NSLog(@"%s:%s;%@;", PRE, #val, [NSNumber numberWithUnsignedLongLong:val])
        #define DLogunsignedshort(val)      NSLog(@"%s:%s;%@;", PRE, #val, [NSNumber numberWithUnsignedShort:val])

        #define DLogGLKMatrix2(val)         NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromGLKMatrix2(val))
        #define DLogGLKMatrix3(val)         NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromGLKMatrix3(val))
        #define DLogGLKMatrix4(val)         NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromGLKMatrix4(val))
        #define DLogGLKVector2(val)         NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromGLKVector2(val))
        #define DLogGLKVector3(val)         NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromGLKVector3(val))
        #define DLogGLKVector4(val)         NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromGLKVector4(val))
        #define DLogGLKQuaternion(val)      NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromGLKQuaternion(val))

        #if TARGET_OS_IPHONE || TARGET_OS_SIMULATOR

            #define DLogUIColor(obj); { CGFloat red = 0.0, green = 0.0, blue = 0.0, alpha =0.0; [obj getRed:&red green:&green blue:&blue alpha:&alpha]; NSLog(@"%s:%s;%@;R: %f G: %f B: %f A: %f", PRE, #obj, obj, red, green, blue, alpha); }

            #define DLogUIView(obj)             NSLog(@"%s:%s;%@;", PRE, #obj, [obj performSelector:@selector(recursiveDescription) withObject:nil])
            #define DLogCGPoint(val)            NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromCGPoint(val))
            #define DLogCGSize(val)             NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromCGSize(val))
            #define DLogCGRect(val)             NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromCGRect(val))
            #define DLogNSPoint(val)            NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromCGPoint((CGPoint)val))
            #define DLogNSSize(val)             NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromCGSize((CGSize)val))
            #define DLogNSRect(val)             NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromCGRect((CGRect)val))
            #define DLogUIOffset(val)           NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromUIOffset(val))
            #define DLogUIEdgeInsets(val)       NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromUIEdgeInsets(val))
            #define DLogCGAffineTransform(val)  NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromCGAffineTransform(val))
            #define DLogCATransform3d(val)      NSLog(@"%s:%s:%@;", PRE, #val, [DLog CATransform3D:val])
            #define DLogUIGestureRecognizerState(val)   NSLog(@"%s:%s:%@;", PRE, #val, [DLog UIGestureRecognizerState:val])

        #elif TARGET_OS_MAC

            #define DLogCGPoint(val)            NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromPoint(NSPointFromCGPoint(val)))
            #define DLogCGSize(val)             NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromSize(NSSizeFromCGSize(val)))
            #define DLogCGRect(val)             NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromRect(NSRectFromCGRect(val)))
            #define DLogNSPoint(val)            NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromPoint(val))
            #define DLogNSSize(val)             NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromSize(val))
            #define DLogNSRect(val)             NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromRect(val))
            #define DLogNSHashTable(obj)        NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromHashTable(val))
            #define DLogNSMapTable(obj)         NSLog(@"%s:%s;%@;", PRE, #val, NSStringFromMapTable(val))

        #endif

#pragma mark - Time Logging Methods

        #define DLogTimeStart(key)             NSDate *__dTime ## key = [NSDate date]
        #define DLogTimeEnd(key)               NSLog(@"%s:%s;%f;", PRE, #key, -([__dTime ## key timeIntervalSinceNow]))

#pragma mark - Thread Logging Methods

        #define DLogMainThread()               NSLog(@"%s:%s;%d:MainThread=%s;", PRE, __PRETTY_FUNCTION__, __LINE__,([NSThread isMainThread]?"YES":"NO"))

#pragma mark - Assertion Methods

    #define DAssertMainThread()                NSParameterAssert([NSThread isMainThread])
    #define DAssertNil(obj)                    NSParameterAssert(obj == nil)
    #define DAssertNonNil(obj)                 NSParameterAssert(obj != nil)


    #else

        #define DLog(format, ...)                   do{}while(0)
        #define DLogFunctionLine()                  do{}while(0)

        #define DLogObject(obj)                     do{}while(0)
        #define DLogNSObject(obj)                   do{}while(0)
        #define DLogException(obj)                  do{}while(0)
        #define DLogClass(val)                      do{}while(0)
        #define DLogSEL(val)                        do{}while(0)
        #define DLogProtocol(val)                   do{}while(0)
        #define DLogPointer(val)                    do{}while(0)
        #define DLogTypeEncoding(val)               do{}while(0)
        #define DLogBytes(val)                      do{}while(0)
        #define DLogByteOrder()                     do{}while(0)

        #define DLogBOOL(val)                       do{}while(0)
        #define DLogNSRange(val)                    do{}while(0)
        #define DLogunichar(val)                    do{}while(0)

        #define DLogid(obj)                         do{}while(0)
        #define DLogCGFloat(val)                    do{}while(0)

        #define DLogchar(val)                       do{}while(0)
        #define DLogdouble(val)                     do{}while(0)
        #define DLogfloat(val)                      do{}while(0)
        #define DLogint(val)                        do{}while(0)
        #define DLogNSInteger(val)                  do{}while(0)
        #define DLoglong(val)                       do{}while(0)
        #define DLoglonglong(val)                   do{}while(0)
        #define DLogshort(val)                      do{}while(0)
        #define DLogunsignedchar(val)               do{}while(0)
        #define DLogunsignedint(val)                do{}while(0)
        #define DLogNSUInteger(val)                 do{}while(0)
        #define DLogunsignedlong(val)               do{}while(0)
        #define DLogunsignedlonglong(val)           do{}while(0)
        #define DLogunsignedshort(val)              do{}while(0)

        #define DLogGLKMatrix2(val)                 do{}while(0)
        #define DLogGLKMatrix3(val)                 do{}while(0)
        #define DLogGLKMatrix4(val)                 do{}while(0)
        #define DLogGLKVector2(val)                 do{}while(0)
        #define DLogGLKVector3(val)                 do{}while(0)
        #define DLogGLKVector4(val)                 do{}while(0)
        #define DLogGLKQuaternion(val)              do{}while(0)

        #define DLogUIColor(obj)                    do{}while(0)
        #define DLogUIView(obj)                     do{}while(0)
        #define DLogCGPoint(val)                    do{}while(0)
        #define DLogCGSize(val)                     do{}while(0)
        #define DLogCGRect(val)                     do{}while(0)
        #define DLogUIOffset(val)                   do{}while(0)
        #define DLogUIEdgeInsets(val)               do{}while(0)
        #define DLogCGAffineTransform(val)          do{}while(0)
        #define DLogCATransform3D(val)              do{}while(0)
        #define DLogUIGestureRecognizerState(val)   do{}while(0)

        #define DLogNSPoint(val)                    do{}while(0)
        #define DLogNSSize(val)                     do{}while(0)
        #define DLogNSRect(val)                     do{}while(0)
        #define DLogNSHashTable(obj)                do{}while(0)
        #define DLogNSMapTable(obj)                 do{}while(0)

        #define DLogStart(key)                      do{}while(0)
        #define DLogEnd(key)                        do{}while(0)

        #define DLogMainThread()                    do{}while(0)
        #define DAssertMainThread()                 do{}while(0)

        #define DAssertNil(obj)                     do{}while(0)
        #define DAssertNonNil(obj)                  do{}while(0)

    #endif
#endif

#endif
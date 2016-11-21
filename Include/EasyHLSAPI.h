/*
	Copyright (c) 2013-2015 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.easydarwin.org
*/
#ifndef _Easy_HLS_API_H
#define _Easy_HLS_API_H

#include "EasyTypes.h"

#define	EasyHLS_Version	"EasyHLS v1.0.16.1105"

enum{
	TS_TYPE_PAT = 0x01000000,
	TS_TYPE_PMT = 0x02000000,
	TS_TYPE_PES = 0x03f00000,

	TS_TYPE_PES_AUDIO         = 0x03100000,
	TS_TYPE_PES_VIDEO_I_FRAME = 0x03200000,
	TS_TYPE_PES_VIDEO_P_FRAME = 0x03400000,
	TS_TYPE_PES_VIDEO_E_FRAME = 0x03800000,
};

#ifdef __cplusplus
extern "C"
{
#endif
	/* 激活 */
	Easy_API int Easy_APICALL EasyHLS_Activate(char *license);

	/* 创建HLSSession  返回为句柄值 */
	Easy_API Easy_HLS_Handle Easy_APICALL EasyHLS_Session_Create(int nCapacity, bool bAllowCache, int version);

	/* 设置HLS参数 strRootDir:以/结尾根目录 strSubDir:以/结尾子目录 strMediaName:媒体名称、nTargetDuration:单个切片时间 nFirstTSIFrameCount生成第一个TS切片的I帧数量默认按时间生成*/
	Easy_API void Easy_APICALL EasyHLS_ResetStreamCache(Easy_HLS_Handle handle, const char * strRootDir, const char* strSubDir, const char* strMediaName, int nTargetDuration, int nFirstTSIFrameCount = 0);
	
	/* 获取具体HLSSession的m3u8文件 */
	Easy_API const char*  Easy_APICALL EasyHLS_GetM3U8File(Easy_HLS_Handle handle);
	
	/* 打包视频 */
	Easy_API int Easy_APICALL EasyHLS_VideoMux(Easy_HLS_Handle handle, unsigned int uiFrameType, unsigned char *data, int dataLength, unsigned long long pcr, unsigned long long pts, unsigned long long dts);
	
	/* 打包音频 */
	Easy_API int Easy_APICALL EasyHLS_AudioMux(Easy_HLS_Handle handle, unsigned char *data, int dataLength, /*u64 pcr,*/ unsigned long long pts, unsigned long long dts=~0);

	/* 释放HLSSession */
	Easy_API void Easy_APICALL EasyHLS_Session_Release(Easy_HLS_Handle handle);

#ifdef __cplusplus
}
#endif

#endif

using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.Security.WinTrust
{
    public unsafe partial struct SIGNER_CONTEXT
    {
        [NativeTypeName("DWORD")]
        public uint cbSize;

        [NativeTypeName("DWORD")]
        public uint cbBlob;

        public unsafe byte *pbBlob;
    }

    public static unsafe partial class Apis
    {
        [DllImport("mssign32.dll", CallingConvention = CallingConvention.StdCall, ExactSpelling = true)]
        [SupportedOSPlatform("windows5.1.2600")]
        public static extern int SignerFreeSignerContext([In]SIGNER_CONTEXT *pSignerContext);
    }
}
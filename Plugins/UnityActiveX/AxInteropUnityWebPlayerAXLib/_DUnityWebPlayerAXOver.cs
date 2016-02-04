using System;
using System.Runtime.InteropServices;
using UnityWebPlayerAXLib;

namespace AxUnityWebPlayerAXLib
{
    [Guid("6130BEAD-7375-4DB7-8B6D-7E41303CE675")]
    [TypeLibType(4288)]
    public interface _DUnityWebPlayerAX
    {
        [DispId(-525)]
        int readyState { get; }
        [DispId(1)]
        string src { get; set; }
              
        [DispId(3)]
        string GetPluginVersion();
        [DispId(4)]
        string GetUnityVersion(string release);
        [DispId(2)]
        void SendMessage(string obj, string method, object val);
        
        

    }
}


using UnityEngine;
using UnityEditor;
using System.Reflection;

namespace CommonUnity
{
    class Demo
    {
        private NavBotAgent mNavBotAgent = null;

        private WWW mWWW = null;

        private AssetBundle mAssetBundle = null;

        /// <summary>
        /// 加载一个场景
        /// </summary>
        public void Load()
        {
            //  加载一个纯粹的Navmesh的.unity3d文件
            //string strTargetPath01 = string.Format( @"{0}{1}.unity3d", 
            //                                        "F:/Heros/CommonUnity/Resources/Unity3dFiles/",
            //                                        "city_ziyoubao_001");

            //mWWW = WWW.LoadFromCacheOrDownload(strTargetPath01, 0);
            //mWWW = new WWW(strTargetPath01);

            //mAssetBundle = AssetBundle.CreateFromFile(strTargetPath01);

            //Application.LoadLevel("city_ziyoubao_001");

            //  加载一个代理机器人
            GameObject obj = new GameObject("NavBotAgent");

            //mNavBotAgent = obj.AddComponent<NavBotAgent>();
        }

        /// <summary>
        /// 卸载一个场景
        /// </summary>
        public void Unload()
        {
            //  卸载机器人
            if (mNavBotAgent != null)
            {
                GameObject.Destroy(mNavBotAgent.gameObject);
                mNavBotAgent = null;
            }

            if (mAssetBundle != null)
            {
                mAssetBundle.Unload(true);
                mAssetBundle = null;
            }

            //  卸载Scene文件
            //if (mWWW != null)
            //{
            //    if (mWWW.assetBundle != null)
            //        mWWW.assetBundle.Unload(true);
            //    mWWW.Dispose();
            //    mWWW = null;
            //}
        }
    }
}

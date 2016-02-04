using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using UnityEngine;

namespace CommonUnity
{
    public class NavBotAgent : MonoBehaviour
    {

        public NavMeshAgent mNavMeshAgent;
        public NavMeshPath mNavMeshPath = new NavMeshPath();
        public Vector3[] mCorners;

        // Use this for initialization
        void Start()
        {
            mNavMeshAgent = gameObject.AddComponent<NavMeshAgent>();
            mNavMeshAgent.height = 2;
            mNavMeshAgent.baseOffset = 0;
            mNavMeshAgent.radius = 0.05f;
            mNavMeshAgent.acceleration = 1000;
            mNavMeshAgent.angularSpeed = 1000;
            mNavMeshAgent.enabled = false;

            //bool success = mNavMeshAgent.FindClosestEdge(out hit);

            //if (success)
            //    transform.position = hit.position;


        }

        NavMeshHit hit;

        public Vector3[] GetPathPoint(Vector3 startpos, Vector3 endpos)
        {
            try
            {
                mNavMeshAgent.enabled = false;

                transform.position = CorrectPos2NavPos(startpos);

                mNavMeshAgent.enabled = true;

                mNavMeshAgent.ResetPath();

                if (mNavMeshAgent.CalculatePath(endpos, mNavMeshPath))
                {
                    mCorners = null;
                    mCorners = new Vector3[mNavMeshPath.corners.Length];
                    for (int i = 0; i < mNavMeshPath.corners.Length; ++i)
                    {
                        mCorners[i] = mNavMeshPath.corners[i];

                    }

                    return mCorners;
                }

            }
            catch (System.Exception e)
            {
                mNavMeshAgent.enabled = false;

                Debug.LogException(e);
            }


            return null;
        }

        Vector3 realNavPos = Vector3.one;

        /// <summary>
        /// 
        /// </summary>
        /// <param name="pos"></param>
        /// <returns></returns>
        private Vector3 CorrectPos2NavPos(Vector3 pos)
        {
            realNavPos = pos;

            return realNavPos;
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Web;
using System.Runtime.Serialization;
using System.Web.Script.Serialization;

namespace js高级.asp
{
    /// <summary>
    /// json 的摘要说明
    /// </summary>
    public class json : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {

            Thread.Sleep(1000);

            context.Response.ContentType = "text/plain";
            var listp = new List<Person>()
            {
                new Person() {Id = "1", Name = "A"},
                new Person() {Id = "2", Name = "B"},
                new Person() {Id = "3", Name = "C"},

            };
            var seri = new JavaScriptSerializer();

            context.Response.Write(seri.Serialize(listp));

            
        }

        public bool IsReusable
        {
            get
            {
                return false;
            }
        }
    }
}
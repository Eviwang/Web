using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Web;
using System.Web.Script.Serialization;

namespace js高级.asp
{
    /// <summary>
    /// SSE 的摘要说明
    /// </summary>
    public class SSE : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {

            context.Response.ContentType = "text/plain";
            var listp = new List<Person>()
            {
                new Person() {Id = "1", Name = "A"},
                new Person() {Id = "2", Name = "B"},
                new Person() {Id = "3", Name = "C"},

            };
            var seri = new JavaScriptSerializer();
            var i = 4;
            listp.Add(new Person(){Id = i++.ToString(),Name = DateTime.Now.ToShortTimeString()});
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
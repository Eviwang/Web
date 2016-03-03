using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(TestKO2.Startup))]
namespace TestKO2
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}

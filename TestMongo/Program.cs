using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MongoDB.Bson.Serialization.Attributes;
using MongoDB.Bson.Serialization.IdGenerators;
using MongoDB.Driver;
using MongoRepository;

namespace TestMongo
{
    class Program
    {
        static void Main(string[] args)
        {

            MongoRepository<TestEntity> repository = new MongoRepository<TestEntity>("mongodb://mongodbapp:mongodbapp@192.168.1.246:27017/gsmp_autotest", "test2");

            repository.Add(new TestEntity()
            {
                Name = "A"
            });
            var result = repository.Where(x => x.Name == "A").ToList();
            Console.WriteLine(result.Count);
            Console.ReadKey();
        }
    }

    public class TestEntity : IEntity
    {
        public string Name { get; set; }

        [BsonId(IdGenerator = typeof(StringObjectIdGenerator))]
        public string Id { get; set; }
    }
}

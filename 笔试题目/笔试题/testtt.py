import random
import unittest
class TestSequenceFunction(unittest.TestCase):
    def setUp(self):
        self.seq = range(10)
        print("call setup")

    def tearDown(self):
        print("call teardown")

    def test_shuffle(self):
        random.shuffe(self.seq)
        self.seq.sort()
        self.assertEqual(self.seq,range(10))
        self.assertEqual(TypeError,random.shuffe,(1,2,3))

    def test_choise(self):
        element = random.choice(self.seq)
        self.assertTrue(element in self.seq)

    def test_sample(self):
        with self.assertRaises(ValueError):
            random.sample(self.seq,20)
        for element in random.sample(self.seq,5):
            self.assertTrue(element in self.seq)

   if __name__ == '__main__':
       unittest.main()

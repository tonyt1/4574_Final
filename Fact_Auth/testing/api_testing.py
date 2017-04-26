import unittest, mock, requests
import fact_generator as FG

api_url = "http://127.0.0.1:8080/api"

class TestInternalMethods(unittest.TestCase):

	def test_get_sentences(self):
		""" Tests that a sentence is split up with proper punctuation.
		"""
		test_sentences = 'This is a test sentence! It should split now. This is the end.'
		print("\nHere are the test sentences: %s" % test_sentences)
		split_sentences = FG.get_sentences(test_sentences)
		self.assertTrue(len(split_sentences) == 3)
		self.assertEqual(split_sentences[0], "This is a test sentence!")
		self.assertEqual(split_sentences[1], "It should split now.")
		self.assertEqual(split_sentences[2], "This is the end.")
		print("\n\n")


	def test_get_fact_subject(self):
		""" Tests that facts can be returned for 'Barack Obama' """
		print("\n\n")
		subject = 'Barack Obama'
		response = FG.get_fact_subject(subject)
		return_subject = response[0]
		facts = response[1]
		self.assertEqual(return_subject, 'Barack Obama')
		self.assertTrue('Obama' in facts)
		print(response)
		print("\n")


	def test_get_fact_subject_fail(self):
		""" Tests that an error message is returned when an invalid subject is given"""
		print("\n\n")
		subject = 'ergopoiewgporewom'
		response = FG.get_fact_subject(subject)
		return_subject = response[0]
		facts = response[1]
		self.assertEqual(return_subject, 'error')
		self.assertTrue('ergopoiewgporewom' in facts)
		print(response)
		print("\n")


	def test_get_fact_random(self):
		""" Tests that a message is returned with a random subject"""
		print("\n\n")
		response1 = FG.get_fact_random()
		subject1 = response1[0]

		response2 = FG.get_fact_random()
		subject2 = response2[0]

		print(subject1, "  -----  ", subject2)
		self.assertFalse(subject1 == subject2)

		print("\n")

class TestExternalMethods(unittest.TestCase):

	@unittest.skipIf(api_url is "", "This test is disabled until a URL has been defined for the API")
	def test_get_fact_subject(self):
		""" Tests that the API can return codes and facts about Barack Obama"""
		url = api_url + "/subject"
		topic = 'Barack Obama'
		payload = {"topic":topic}
		response = requests.get(url, params=payload)
		self.assertEqual(200, response.status_code)
		json_response = response.json()
		return_subject = json_response["subject"]
		self.assertEqual(topic, return_subject)
		fact = json_response["facts"]
		self.assertTrue('Obama' in fact)

	@unittest.skipIf(api_url is "", "This test is disable until a URL has been defined for the API")
	def test_get_fact_subject_fail(self):
		""" Tests that an error message is returned when an invalid subject is given"""
		url = api_url + "/subject"
		topic = 'ergopoiewgporewom'
		payload = {"topic":topic}
		response = requests.get(url, params=payload)
		self.assertEqual(404, response.status_code)		
		json_response = response.json()
		return_output = json_response["error"]
		self.assertTrue(topic in return_output)

	@unittest.skipIf(api_url is "", "This test is disable until a URL has been defined for the API")
	def test_get_fact_random(self):
		""" Tests that a message is returned with a random subject"""
		url = api_url + "/random"
		response1 = requests.get(url)
		json_response1 = response1.json()
		subject1 = json_response1["subject"]

		response2 = requests.get(url)
		json_response2 = response2.json()
		subject2 = json_response2["subject"]

		print("\n\n", subject1, "  -----  ", subject2, "\n")
		self.assertFalse(subject1 == subject2)


if __name__ == '__main__':
	unittest.main()
import nltk.data, wikipedia, random
import wikipedia.exceptions as WE



"""	Function to split up a paragraph based on formatting in the 
    Natural Language Toolkit module. Maintains all abbreviations
    and punctuations and keeps sentence structure. 
"""
def get_sentences(string):
    tokenizer = nltk.data.load('tokenizers/punkt/english.pickle')
    split_str = '\n'.join(tokenizer.tokenize(string))
    sentences = split_str.split('\n')
    return sentences



""" 	Given a specific subject, this will return a sentence or two
    (depending on the information available on Wikipedia) on that
    subject. If more than one page is found about that topic, then
    one of the topics is chosen at random, then facts pulled from 
    that page's summary. If a page cannot be found about that topic,
    then an error message is returned
"""
def get_fact_subject(subject):
    try:
        page = wikipedia.page(subject)        
    except WE.DisambiguationError as error:
        titles = error.options
        subject = titles[random.randint(0, len(titles) - 2)]
        page = wikipedia.page(subject)
    except WE.PageError as error:
        return "error", ("Sorry! Couldn't find any facts about %s." % subject)
    summary = page.summary
    sentences = get_sentences(summary)
    if len(sentences) == 1:
        return subject, sentences[0]
    return subject, sentences[0] + " " + sentences[random.randint(1, len(sentences) - 1)]



"""	Similar to the previous function, but produces a random subject
    and uses the previous function to generate the facts on that 
    subject
"""
def get_fact_random():
    subject = wikipedia.random(1)
    return get_fact_subject(subject)
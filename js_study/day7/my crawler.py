import re
import requests
url = 'http://127.0.0.1:5000/smzy?callback=mzy&username=smzy&age=18&_=1702307994356'
resp = requests.get(url)
# Sometimes the call is not written, and the JSON data is returned directly
print(resp.text.replace('mzy','').replace('(','').replace(')',''))
obj = re.compile(r"\((?P<data>\{.*\})\)")
import json
dic = json.loads(obj.search(resp.text).group('data'))
# plan 2 generic logic for handling jsonp data
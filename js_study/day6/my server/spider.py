import requests
import re
resp = requests.get('http://127.0.0.1:5000/a?username=123456&pwd=123')
print(resp.request.headers)
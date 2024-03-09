from flask import Flask,render_template,request
import json
app = Flask(__name__)
@app.route('/')
def index():
    return render_template('index.html')
@app.route('/smzy')
def smzy():

    dic = {
        'result':[1,2,3,4,5,6,7,8,9,10],
        "code":200,
        "msg":"请求成功"
    }

    cb = request.args.get('callback')
    return cb + '(' + json.dumps(dic) + ')'
    # The returned data cannot be directly data
    # need to put the data in js code
    # return dic
if __name__ == '__main__':
    app.run(debug=True)
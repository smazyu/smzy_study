from flask import Flask, render_template, request

app = Flask(__name__)

@app.route('/')
def qiaofu():
    with open('index.html', 'r', encoding='utf-8') as f:
        content = f.read()
    return content

@app.route('/a')
def y():
    uname = request.args.get('username')
    ua = request.headers.get('User-Agent')
    referer = request.headers.get('Referer', 'No referer')
    # Form and json are two different paths for the server
    # it s two different formats
    if not ua:
        ua = 'No ua'

    if 'python' in ua:
        print('you re a web crawler')
        return 'you re a web crawler'
    data = [{'name': 'age'}]
    return {
        'code': 0,
        'data': data,
        'msg': 'success'
    }
if __name__ == "__main__":
    app.run(debug=True, port=5000)
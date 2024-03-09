from flask import Flask, render_template, request, jsonify

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/smzy', methods=['GET', 'POST'])
def smzy():
    if request.method == 'POST':
        # 确保请求的Content-Type是application/json
        if request.is_json:
            data = request.get_json()  # 获取JSON数据
            uname = data.get('username')  # 从JSON数据中获取username
            print(uname)  # 在服务器控制台打印username
        else:
            return jsonify({"code": 400, "msg": "请求头Content-Type不是application/json"}), 400

    dic = {
        'result': [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
        "code": 200,
        "msg": "请求成功"
    }
    # 使用jsonify来确保返回的是JSON格式的响应
    return jsonify(dic)

if __name__ == '__main__':
    app.run(debug=True)
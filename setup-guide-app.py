from flask import Flask, render_template
HOST = 'localhost'
PORT = 3000


app = Flask(__name__)


@app.route('/')
def home():
    return render_template('setup-guide.html')


if __name__ == '__main__':
    app.run(host=HOST, port=PORT)

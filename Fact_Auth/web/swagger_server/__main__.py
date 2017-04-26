#!/usr/bin/env python3

import connexion
from .encoder import JSONEncoder


if __name__ == '__main__':
    app = connexion.App(__name__, specification_dir='./swagger/')
    app.app.json_encoder = JSONEncoder
    app.add_api('swagger.yaml', arguments={'title': 'Generates a random fact based on the unofficial Wikipedia API  and Natural Language Toolkit modules. API&#39;s use authentication with either Username and Password, or Token.'})
    app.run(host='0.0.0.0', port=8000)

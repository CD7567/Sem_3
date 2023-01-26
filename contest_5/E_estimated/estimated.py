with open('source', 'rb') as inf:
    ss = inf.read()
    with open('cracked', 'wb') as out:
        out.write(ss.replace(b'\x00\xca\x9a\x3b', b'\x00\xca\x9a\x77'))
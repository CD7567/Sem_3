with open('source', 'rb') as inf:
    ss = inf.read()
    with open('cracked', 'wb') as out:
        out.write(ss.replace(b'\xe5\x0d\x00\x53\xe3\x01\x00\x00\x1a', b'\xe5\x0d\x00\x53\xe3\x01\x00\x00\x0a'))
Export to temporary pem file

openssl pkcs12 -in protected.p12 -nodes -out temp.pem
 -> Enter password
Convert pem back to p12

openssl pkcs12 -export -in temp.pem  -out unprotected.p12
-> Just press [return] twice for no password

openssl pkcs12 -in unprotected.p12 -nodes -out cert.pem

rm temp.pem
// Generate Private key for root : openssl genpkey -algorithm RSA -out root_private_key.pem
// Generate certificate from private key : openssl req -new -key root_private_key.pem -out root_csr.pem
// sign the certificate from its self : openssl x509 -req -in root_csr.pem -signkey root_private_key.pem -out root_cert.pem




// Generate Private key for L1 : openssl genpkey -algorithm RSA -out L1_private_key.pem
// Generate Intermediate1 L1 Certificate Signing Request (CSR): openssl req -new -key L1_private_key.pem -out L1_csr.pem
// sign L1 certificate from root certificate: openssl x509 -req -in L1_csr.pem -CA root_cert.pem -CAkey root_private_key.pem -out signed_L1_certificate.pem -CAcreateserial


// Generate Private key for L2 : openssl genpkey -algorithm RSA -out L2_private_key.pem
// Generate Intermediate1 L2 Certificate Signing Request (CSR): openssl req -new -key L2_private_key.pem -out L2_csr.pem
// sign L2 certificate from root certificate: openssl x509 -req -in L2_csr.pem -CA root_cert.pem -CAkey root_private_key.pem -out signed_L2_certificate.pem -CAcreateserial


//Verify L1 Certificate against the Root Certificate : openssl verify -CAfile root_cert.pem signed_L1_certificate.pem
//Verify L2 Certificate against the Root Certificate : openssl verify -CAfile root_cert.pem signed_L2_certificate.pem

// Extracts the modulus: openssl rsa -in L2_private_key.pem -noout -modulus // private key for l2
//					   : openssl x509 -in signed_L2_certificate.pem -noout -modulus  



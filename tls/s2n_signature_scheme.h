/*
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#pragma once

#include "api/s2n.h"
#include <strings.h>

#include "crypto/s2n_hash.h"
#include "crypto/s2n_signature.h"
#include "crypto/s2n_ecc_evp.h"

struct s2n_signature_scheme {
    uint16_t iana_value;
    s2n_hash_algorithm hash_alg;
    s2n_signature_algorithm sig_alg;
    uint8_t minimum_protocol_version;
    uint8_t maximum_protocol_version;
    uint16_t libcrypto_nid;

    /* Curve is only specified for ECDSA Signatures */
    struct s2n_ecc_named_curve const *signature_curve;
};

struct s2n_signature_preferences{
    uint8_t count;
    const struct s2n_signature_scheme *const *signature_schemes;
};

/* RSA PKCS1 */
/* s2n_rsa_pkcs1_md5_sha1 is not in any preference list, but it is needed since it's the default for TLS 1.0 and 1.1 if
 * no SignatureScheme is sent. */
extern const struct s2n_signature_scheme s2n_rsa_pkcs1_md5_sha1;
extern const struct s2n_signature_scheme s2n_rsa_pkcs1_sha1;
extern const struct s2n_signature_scheme s2n_rsa_pkcs1_sha224;
extern const struct s2n_signature_scheme s2n_rsa_pkcs1_sha256;
extern const struct s2n_signature_scheme s2n_rsa_pkcs1_sha384;
extern const struct s2n_signature_scheme s2n_rsa_pkcs1_sha512;

/* TLS 1.2 Compatible ECDSA Schemes */
extern const struct s2n_signature_scheme s2n_ecdsa_sha1;
extern const struct s2n_signature_scheme s2n_ecdsa_sha224;
extern const struct s2n_signature_scheme s2n_ecdsa_sha256;
extern const struct s2n_signature_scheme s2n_ecdsa_sha384;
extern const struct s2n_signature_scheme s2n_ecdsa_sha512;

/* TLS 1.3 Compatible ECDSA Schemes */
extern const struct s2n_signature_scheme s2n_ecdsa_secp256r1_sha256;
extern const struct s2n_signature_scheme s2n_ecdsa_secp384r1_sha384;
extern const struct s2n_signature_scheme s2n_ecdsa_secp521r1_sha512;

/* RSA PSS */
/*
 * Use RSA-PSS-RSAE instead of RSA-PSS-PSS in order to work with older certificates.
 * For more info see: https://crypto.stackexchange.com/a/58708
 */
extern const struct s2n_signature_scheme s2n_rsa_pss_pss_sha256;
extern const struct s2n_signature_scheme s2n_rsa_pss_pss_sha384;
extern const struct s2n_signature_scheme s2n_rsa_pss_pss_sha512;
extern const struct s2n_signature_scheme s2n_rsa_pss_rsae_sha256;
extern const struct s2n_signature_scheme s2n_rsa_pss_rsae_sha384;
extern const struct s2n_signature_scheme s2n_rsa_pss_rsae_sha512;

extern const struct s2n_signature_preferences s2n_signature_preferences_20140601;
extern const struct s2n_signature_preferences s2n_signature_preferences_20200207;
extern const struct s2n_signature_preferences s2n_signature_preferences_20201021;
extern const struct s2n_signature_preferences s2n_signature_preferences_20210816;
extern const struct s2n_signature_preferences s2n_signature_preferences_null;

extern const struct s2n_signature_preferences s2n_certificate_signature_preferences_20201110;

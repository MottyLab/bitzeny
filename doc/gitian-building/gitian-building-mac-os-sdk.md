Gitian building Mac OS SDK
==========================

Get MacOSX10.11.sdk.tar.gz
--------------------------

[https://github.com/MZaf/MacOSX10.11.sdk](https://github.com/MZaf/MacOSX10.11.sdk)


Copy SDK to Gitian VM:
----------------------

Login to the VM and:

```bash
mkdir -p gitian-builder/inputs
mv MacOSX10.11.sdk.tar.gz gitian-builder/inputs
```


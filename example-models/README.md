#Resnet50 setup

git clone https://github.com/tarafdar/AIgean.git
git clone https://github.com/UofT-HPRC/galapagos.git
git clone https://github.com/violatingcp/hls4ml.git
cd hls4ml 
git checkout -b sc20_test
pip install -e .
cd example-models
hls4ml convert -c onnx-config.yml
#ips is located in project/firware

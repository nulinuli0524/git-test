import convertPdfToPcl from '../../native/convert';

@Entry
@Component
struct IndexPage {
  build() {
    Column() {
      Button('Convert PDF')
        .width('200px')
        .height('60px')
        .onClick(() => { this.onConvert(); });
    }
  }

  private onConvert() {
    const inPath = '/data/Input.pdf';
    const outPath = '/data/Output.pclm';
    convertPdfToPcl(inPath, outPath);
  }
}

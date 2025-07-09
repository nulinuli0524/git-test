<template>
  <div>
    <button onClick="{{onConvert}}">Convert PDF</button>
  </div>
</template>

<script lang="ets">
export default class MainAbility {
  onConvert() {
    convertPdfToPcl('/data/Input.pdf', '/data/Output.pclm');
  }
}
</script>
